#ifndef RUMMY_UI_H
#define RUMMY_UI_H

#include <iostream>
#include <list>
#include <vector>
#include "GameUI.h"
#include "Player.h"
#include "Card.h"
#include "RummyTable.h"
#include "RummyDeck.h"


/**
 * A UI for a round of rummy.
 *
 * @author Steven Deutekom
 * @date nov 29 2019
 */
class RummyUI : public GameUI {
 public:
  RummyUI();
  virtual ~RummyUI();

  virtual void takeTurn(Player* p);
  virtual void displayTable(RummyTable* table);
  virtual void displayHand(std::list<Card*>* hand);
  virtual int drawFromDeck(RummyDeck* deck);
  virtual std::vector<int> playMeld(std::list<Card*>* hand);
  virtual int layOff(std::list<Card*>* hand);
  virtual void turnOver(Player* player);
  virtual void pickedCard(Card* c);

  virtual unsigned int requestCard(Player* player,
                                   std::list<Card*>* hand);
  virtual void playFailed();
  virtual void playSucceeded();
  virtual void showGameOutcome(std::vector<Player*> players);
  virtual void outOfGame(Player* player);
};

#endif
