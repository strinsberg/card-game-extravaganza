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

  /**
   * Display information for the start of a players turn.
   *
   * @param p The player taking the turn.
   */
  virtual void takeTurn(Player* p);

  /**
   * Display the melds on the table.
   *
   * @param table The table.
   */
  virtual void displayTable(RummyTable* table);

  /**
   * Display the cards in a hand.
   *
   * @param hand The hand to display.
   */
  virtual void displayHand(std::list<Card*>* hand);

  /**
   * Ask a player where to draw from.
   *
   * @param deck The rummy deck with a deck and discard.
   * @return 1 to draw from deck, 2 to draw from discard, and 3 to put the
   * discard in the deck and draw from the top.
   */
  virtual int drawFromDeck(RummyDeck* deck);

  /**
   * Let a player play a meld.
   * The returned position are 1 based. If the player has decided not to play
   * a meld the size of the returned vector will be 0.
   *
   * @param hand The players hand.
   * @return a list of the positions of the cards in the hand.
   * 1 based. 
   */
  virtual std::vector<int> playMeld(std::list<Card*>* hand);

  /**
   * Let a player layoff a card onto the table.
   * Returned index is 1 based. 0 means they did not want to layoff.
   *
   * @param hand The players hand.
   * @return the index of the card to layoff.
   */
  virtual int layOff(std::list<Card*>* hand);

  /**
   * Display information when the turn is over.
   * Waits for the player to press enter.
   *
   * @param player The player taking the turn.
   */
  virtual void turnOver(Player* player);

  /**
   * Display the card that was just picked up.
   *
   * @param c The card that was picked up.
   */
  virtual void pickedCard(Card* c);

  virtual unsigned int requestCard(Player* player,
                                   std::list<Card*>* hand);
  virtual void playFailed();
  virtual void playSucceeded();
  virtual void showGameOutcome(std::vector<Player*> players);
  virtual void outOfGame(Player* player);
};

#endif
