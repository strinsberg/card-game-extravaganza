#include <vector>
#include "Rummy.h"
#include "RummyDeck.h"
#include "GameUI.h"
#include "Card.h"
#include "Player.h"


Rummy::Rummy(GameUI* ui, RummyDeck* deck) : Game(ui, deck), rummyDeck(deck) {}

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
