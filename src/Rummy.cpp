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
//   Player* player = players(playerNum);
//   
//   displayTurnInfo(player);
//   displayHand(player);
//   pickupCard(player);
//   playMelds(player);
//   layOff(player);
}

void Rummy::displayTurnInfo(Player* p) {
//    rummyUI->takeTurn(player);
//    rummyUI->displayTable();
}

void Rummy::displayHand(Player* p) {
//   sortHand(hand);
//   rummyUI->displayHand(hand);
}

void Rummy::pickupCard(Player* p) {
//   int pickup = rummyUI->drawFromDeck(rummyDeck);
//   
//   Card* c;
//   if (pickup == 1)
//     c = rummyDeck->getCard();
//   else if (pickup == 2)
//     c = rummyDeck->takeDiscardTop();
//   else {
//     rummyDeck->flipDiscard();
//     c = rummyDeck->getCard();
//   }
//   
//   player->addCard(c);
}

void Rummy::playMelds(Player* p) {
//   bool melds = true;
//   while (melds) {
//     std::vector<int> meldIdxs = rummyUI->playMeld(hand);
//   if (meldIdxs.size()) {
//       std::vector<card> meld;
//       // validate set or run before removeing cards
//       for (auto i : meldIdxs)
//         meld.push_back(player->getCard(i));
//         if (validateMeld(meld)) {
//           // remove cards from hand
//           // redisplay hand? table? say play succeeded?
//         } else {
//           rummyUI->playFailed();
//         }
//     } else {
//       melds = false;
//     }
//   }
}

void Rummy::layOff(Player* p) {
//   bool layoff = true;
//   while (layoff) {
//     int idx = rummyUI->layOff(hand);
//     if (idx > 0) {
//       // get the card and check it and remove it
//       Card* card = player->getCard(idx);
//       try {
//         rummyTable->addCard(card);
//         hand->remove(card);
//         // say anything??
//       } catch (unmet_precondition_error& e) {
//         rummyUI->playFailed();
//       }
//     } else {
//       layoff = false;
//     }
//   }
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
