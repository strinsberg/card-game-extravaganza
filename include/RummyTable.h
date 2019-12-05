#ifndef RUMMY_TABLE_H
#define RUMMY_TABLE_H


#include <vector>
#include "Card.h"


/**
 * Holds all melds and cards that have been played during a Rummy game.
 *
 * @author Steven Deutekom
 * @date Nov 29 2019
 */
class RummyTable {
 public:
  RummyTable();
  virtual ~RummyTable();

  /**
   * Add a meld to the table.
   * Melds are sets or runs.
   *
   * @param meld The vector of cards representing a meld.
   */
  virtual void addMeld(std::vector<Card*> meld);

  /**
   * Adds a card to a meld on the table.
   * If there is no place to put the card throw an error.
   *
   * @precondition The card must be playable.
   * @param card The card to play.
   * @throws unmet_precondition_error if the card cannot be added to any meld.
   */
  virtual void addCard(Card* c);

  /**
   * Returns a pointer to all the melds on the table.
   *
   * @return A vector of melds.
   */
  virtual std::vector<std::vector<Card*>>& getMelds();

  /**
   * Returns a vector with all the cards and removes them from the table.
   *
   * @return All the cards on the table.
   */
  virtual std::vector<Card*> takeAllCards();

  virtual bool validateMeld(const std::vector<Card*>& meld);

 protected:
  std::vector<std::vector<Card*>> table;

  bool isSet(const std::vector<Card*>& meld);
};

#endif
