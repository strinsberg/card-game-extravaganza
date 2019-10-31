#include "Game.h"
#include "Exceptions.h"
#include <vector>
#include <list>

Game::~Game() {
    for (unsigned int i=0; i < players.size(); ++i) {
        delete players[i];
    }
    players.clear();

    for (unsigned int i=0; i < playersGoneOut.size(); ++i) {
        delete playersGoneOut[i];
    }
    playersGoneOut.clear();

    delete deck;
    delete ui;
}

void Game::addPlayer(Player* p) {
    players.push_back(p);
}

void Game::start() {
    if (players.empty())
        throw game_init_error("No players for game");

    // Deal cards
    deck->shuffle();
    dealCards(players);

    unsigned int turn = 0;
    Card* c;
    Player* p = players.front();
    do {
        p = players.at(turn);
        do {
            beforeTurn(turn, players.size());
            int index = ui->requestCard(players.at(playerAsking), p->getHand());
            c = p->getCard(index);
            afterTurn(p, &players, c);
        } while (!turnOver());

        checkIfPlayerOut();
        turn = ++turn % players.size();
    } while (!isOver());
    ui->showGameOutcome(players);
}

std::vector<Player*> Game::getPlayers() {
    return players;
}

void Game::checkIfPlayerOut() {
    std::vector<Player*>::iterator noCards = players.end();
    for (std::vector<Player*>::iterator player = players.begin();
            player != players.end();
            ++player ) {
        if ((*player)->getHand()->size() == 0) {
            noCards = player;
            ui->outOfGame(*player);
        }
    }

    if (noCards != players.end()) {
        playersGoneOut.push_back(*noCards);
        players.erase(noCards);
    }
}

bool Game::hasSet(std::list<Card*>* hand, unsigned int setSize) {
    std::list<Card*> toRemove;
    for (std::list<Card*>::iterator checking = hand->begin();
            checking != hand->end();
            ++checking) {
        toRemove.clear();
        unsigned int count = 0;
        for (std::list<Card*>::iterator card = hand->begin();
                card != hand->end(); ++card) {
            if ((*checking)->rank == (*card)->rank) {
                count++;
                toRemove.push_back(*card);
            }
        }

        if (count == setSize) {
            for (std::list<Card*>::iterator card = toRemove.begin();
                    card != toRemove.end();
                    ++card) {
                Card* toDelete = *card;
                hand->remove(*card);
                delete toDelete;
            }
            return true;
        }
    }
    return false;
}
