#include "RummyTable.h"


RummyTable::RummyTable() {}

RummyTable::~RummyTable() {}

void RummyTable::addMeld(std::vector<Card*> meld) {

}

void RummyTable::addCard(Card* c) {

}

const std::vector<std::vector<Card*>>& RummyTable::getMelds() {
  return table;
}

std::vector<Card*> RummyTable::takeAllCards() {
  return std::vector<Card*>();
}
