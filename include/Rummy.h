#ifndef RUMMY_CONTROLLER_H
#define RUMMY_CONTROLLER_H

#include <vector>
#include "Game.h"
#include "Player.h"
#include "Card.h"
#include "RummyDeck.h"
#include "RummyTable.h"
#include "GameUI.h"


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
  Rummy(GameUI* ui, RummyDeck* deck);
  virtual ~Rummy();

  /**
   * Counts the points left in a players hand.
   *
   * @param p The player.
   * @return The number of points left in the players hand.
   */
  virtual int countPoints(Player*);

  virtual void dealCards(std::vector<Player*> p);
  virtual void beforeTurn(unsigned int playerNum,
                          unsigned int numPlayers);
  virtual void afterTurn(Player* currentPlayer, std::vector<Player*>* players,
                         Card* played);
  virtual bool turnOver();
  virtual bool isOver();

 private:
  RummyDeck* rummyDeck;
  RummyTable table;
};

#endif
