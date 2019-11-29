#ifndef RUMMY_DECK_H
#define RUMMY_DECK_H

#include <vector>
#include "Card.h"
#include "Deck.h"


/**
 * A Deck for Rummy with a discard pile.
 * Could also be used for games that need a normal deck with a discard pile.
 *
 * @author Steven Deutekom
 * @date November 28 2019
 */
class RummyDeck : public Deck {
 public:
  RummyDeck();
  virtual ~RummyDeck();
  
  /**
   * Get a pointer to the top card of the discard.
   * Does not remove the card.
   *
   * @return the top card of the discard pile.
   */
  virtual Card* topDiscard();
  
  /**
   * Add a card to the top of the discard pile.
   * Transfers ownership to the deck.
   *
   * @param c The card to add.
   */
  virtual void addDiscard(Card* c);
  
  /**
   * Takes the top card from the discard pile.
   * Transfers ownership to the caller.
   *
   * @return the top card of the discard pile.
   */
  virtual Card* getDiscard();

  /**
   * Returns the number of cards in the discard pile.
   *
   * @return size of the discard pile.
   */
  virtual unsigned int discardSize();

  /**
   * Puts the entire discard pile into the deck.
   * Keeps the same order but flips it over and puts all cards into the deck.
   * 
   * @precondition Deck must be empty.
   */
  virtual void flipDiscard();
  
  /**
   * Flips a card from the top of the deck and puts it on top of the discard.
   */
  virtual void discardDeckTop();

 protected:
  std::vector<Card*> discard;
};

#endif
