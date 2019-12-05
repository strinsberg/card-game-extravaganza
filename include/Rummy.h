#ifndef RUMMY_CONTROLLER_H
#define RUMMY_CONTROLLER_H

#include <vector>
#include <list>
#include "Game.h"
#include "Player.h"
#include "Card.h"
#include "RummyDeck.h"
#include "RummyTable.h"
#include "RummyUI.h"


/**
 * A controller for playing a game of rummy.
 *
 * @author Steven Deutekom
 * @date nov 29 2019
 */
class Rummy : public Game {
 public:
  /**
   * Creates the Rummy object with a given ui and deck.
   *
   * @param ui The UI for the game.
   * @param deck The deck for the game.
   */
  Rummy(RummyUI* ui, RummyDeck* deck);
  virtual ~Rummy();

  /**
   * Counts the points left in a players hand.
   *
   * @param p The player.
   * @return The number of points left in the players hand.
   */
  virtual int countPoints(Player*);

  /**
   * Part of the turn where turn info is displayed.
   *
   * @param p The player taking the turn.
   */
  virtual void displayTurnInfo(Player* p);

  /**
   * Sort and display the players hand.
   *
   * @param p The player taking the turn.
   */
  virtual void displayHand(Player* p);

  /**
   * Part of the turn where the player picks up a card.
   *
   * @param p The player taking the turn.
   */
  virtual void pickupCard(Player* p);

  /**
   * The part of the turn where the player can play melds.
   *
   * @param p The player taking the turn.
   */
  virtual void playMelds(Player* p);
  
  /**
   * Part of the turn where the player can layoff cards.
   *
   * @param p The player taking the turn.
   */
  virtual void layOff(Player* p);

  /**
   * @return the rummy table where melds are kept.
   */
  virtual RummyTable* getTable() {return table;}

  /**
   * Sort a hand by suit and value.
   *
   * @param hand The hand to sort.
   */
  void sortHand(std::list<Card*>* hand);

  virtual void dealCards(std::vector<Player*> p);
  virtual void beforeTurn(unsigned int playerNum,
                          unsigned int numPlayers);
  virtual void afterTurn(Player* currentPlayer, std::vector<Player*>* players,
                         Card* played);
  virtual bool turnOver();
  virtual bool isOver();

 private:
  RummyDeck* rummyDeck; // Pointers to call rummy specific methods
  RummyUI* rummyUI;     // This memory is freed in parent Game class
  RummyTable* table;
};

#endif
