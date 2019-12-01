#include <vector>
#include "Rummy.h"
#include "RummyDeck.h"
#include "RummyUI.h"
#include "Card.h"
#include "Player.h"


Rummy::Rummy(RummyUI* ui, RummyDeck* deck) : Game(ui, deck), rummyDeck(deck),
  rummyUI(ui) {}

Rummy::~Rummy() {}

int Rummy::countPoints(Player* p) {
  int sum = 0;
  for (auto c : *(p->getHand())) {
    int rank = static_cast<int>(c->rank);
    if (rank > 9)
      sum += 10;
    else
      sum += rank + 1;
  }
  return sum;
}

void Rummy::dealCards(std::vector<Player*> p) {
    unsigned int playerNum = 0;
    unsigned int numPlayers = p.size();
    unsigned int numCards = numPlayers == 2 ? 10 : 7;

    for (unsigned int i = 0; i < numPlayers * numCards; i++) {
        Player* p = players.at(playerNum);
        p->addCard(deck->getCard());
        playerNum = (++playerNum) % numPlayers;
    }
}

void Rummy::beforeTurn(unsigned int playerNum,
                       unsigned int numPlayers) {
}

void Rummy::afterTurn(Player* currentPlayer, std::vector<Player*>* players,
                      Card* played) {
}

bool Rummy::turnOver() {
  return true;
}

bool Rummy::isOver() {
  return playersGoneOut.size() > 0;
}
