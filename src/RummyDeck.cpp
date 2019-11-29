#include <vector>
#include "RummyDeck.h"
#include "Deck.h"
#include "Card.h"


RummyDeck::RummyDeck() : Deck() {}

RummyDeck::~RummyDeck() {}

Card* RummyDeck::topDiscard() {}

void RummyDeck::addDiscard(Card* c) {}

Card* RummyDeck::getDiscard() {}

unsigned int RummyDeck::discardSize() {}

void RummyDeck::flipDiscard() {}

void RummyDeck::discardDeckTop() {}
