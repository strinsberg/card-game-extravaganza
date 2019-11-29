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

Card* RummyDeck::getDiscard() {}

unsigned int RummyDeck::discardSize() {}

void RummyDeck::flipDiscard() {}

void RummyDeck::discardDeckTop() {
  addDiscard(getCard());    
}
