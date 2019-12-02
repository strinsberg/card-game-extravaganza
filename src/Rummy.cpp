#include <vector>
#include "Rummy.h"
#include "RummyDeck.h"
#include "RummyUI.h"
#include "Card.h"
#include "Player.h"
#include "Exceptions.h"


Rummy::Rummy(RummyUI* ui, RummyDeck* deck) : Game(ui, deck), rummyDeck(deck),
  rummyUI(ui), table(new RummyTable()) {}

Rummy::~Rummy() {
  delete table;
}

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
//   Player* player = players(playerNum);
//   
//   displayTurnInfo(player);
//   displayHand(player);
//   pickupCard(player);
//   playMelds(player);
//   layOff(player);
}

void Rummy::displayTurnInfo(Player* p) {
  rummyUI->takeTurn(p);
  rummyUI->displayTable(table);
}

void Rummy::displayHand(Player* p) {
 sortHand(p->getHand());
 rummyUI->displayHand(p->getHand());
}

void Rummy::pickupCard(Player* p) {
  int pickup = rummyUI->drawFromDeck(rummyDeck);
 
  Card* c;
  if (pickup == 1)
    c = rummyDeck->getCard();
  else if (pickup == 2)
    c = rummyDeck->takeDiscardTop();
  else {
    rummyDeck->flipDiscard();
    c = rummyDeck->getCard();
  }
 
  p->addCard(c);
}

void Rummy::playMelds(Player* p) {
  bool melds = true;
  while (melds) {
    std::vector<int> meldIdxs = rummyUI->playMeld(p->getHand());
    if (meldIdxs.size()) {
      std::vector<Card*> meld;
      // validate set or run before removeing cards
      for (auto i : meldIdxs)
        meld.push_back(p->getCard(i - 1));
      try {
        table->addMeld(meld);
        for (auto c : meld)
          p->getHand()->remove(c);
        // redisplay hand? table? say play succeeded?
      } catch (unmet_precondition_error & e) {
        rummyUI->playFailed();
      }
    } else {
      melds = false;
    }
  }
}

void Rummy::layOff(Player* p) {
  bool layoff = true;
  while (layoff) {
    int idx = rummyUI->layOff(p->getHand());
    if (idx > 0) {
      // get the card and check it and remove it
      Card* card = p->getCard(idx);
      try {
        table->addCard(card);
        p->getHand()->remove(card);
        // say anything??
      } catch (unmet_precondition_error& e) {
        rummyUI->playFailed();
      }
    } else {
      layoff = false;
    }
  }
}

void Rummy::sortHand(std::list<Card*>* hand) {

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
