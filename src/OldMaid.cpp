#include "OldMaid.h"
#include <list>
#include <vector>

bool hasSet(std::list<Card*>*);
void checkPlayerOut(std::vector<Player*>*, GameUI*);

void OldMaid::dealCards(std::vector<Player*> players) {
    unsigned int playerNum = 0;
    unsigned int deckSize = deck->size();

    for (unsigned int i = 0; i < deckSize; i++) {
        Player* p = players.at(playerNum);
        p->addCard(deck->getCard());
        playerNum = (++playerNum) % players.size();
    }
}

void OldMaid::beforeTurn(unsigned int playerNum,
                               unsigned int numPlayers) {
    playerAsking = (playerNum+1)%numPlayers;
}

void OldMaid::afterTurn(Player* currentPlayer,
                              std::vector<Player*>* players,
                              Card* played) {
    // Move card from one player to the other
    Player* receiver = players->at(playerAsking);
    std::list<Card*>* hand = currentPlayer->getHand();
    std::list<Card*> toRemove;
    for (std::list<Card*>::iterator card = hand->begin();
            card != hand->end(); ++card) {
        if ((*card) == played) {
            receiver->getHand()->push_back(*card);
            toRemove.push_back(*card);
        }
    }

    if (toRemove.size() > 0) {
        for (std::list<Card*>::iterator card = toRemove.begin();
                card != toRemove.end();
                ++card)
            hand->remove(*card);
    }

    // Check if receiver have a set of cards
    if (hasSet(receiver->getHand(), 2)) {
        ui->playSucceeded();
    } else {
        ui->playFailed();
    }
}

bool OldMaid::turnOver() {
    return true;
}

bool OldMaid::isOver() {
    if (players.size() == 1)
        return true;

    return false;
}
