#include <vector>
#include "RummyDeck.h"
#include "Deck.h"
#include "Card.h"


RummyDeck::RummyDeck() : Deck() {}

RummyDeck::~RummyDeck() {}

Card* RummyDeck::topDiscard() {
  return discard.back();
}

void RummyDeck::addDiscard(Card* c) {
  discard.push_back(c);
}

Card* RummyDeck::takeDiscardTop() {
  if (discard.empty())
    return nullptr;

  Card* c = topDiscard();
  discard.erase(discard.end() - 1);
  return c;
}

unsigned int RummyDeck::discardSize() {
  return discard.size();
}

void RummyDeck::flipDiscard() {}

void RummyDeck::discardDeckTop() {
  addDiscard(getCard());
}
