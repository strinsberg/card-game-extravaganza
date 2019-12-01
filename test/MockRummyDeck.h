#ifndef MOCK_RUMMY_DECK_H
#define MOCK_RUMMY_DECK_H

#include "gmock/gmock.h"
#include "RummyDeck.h"
#include "Card.h"

class MockRummyDeck : public RummyDeck {
 public:
  MockRummyDeck() {}
  virtual ~MockRummyDeck() {}

  MOCK_METHOD0(topDiscard, Card*());
  MOCK_METHOD1(addDiscard, void(Card* c));
  MOCK_METHOD0(takeDiscardTop, Card*());
  MOCK_METHOD0(discardSize, unsigned int());
  MOCK_METHOD0(flipDiscard, void());
  MOCK_METHOD0(discardDeckTop, void());
  
  MOCK_METHOD0(getCard, Card*());
  MOCK_METHOD0(size, unsigned int());
  MOCK_METHOD0(shuffle, void());
};

#endif
