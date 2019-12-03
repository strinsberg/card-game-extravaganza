#include <vector>
#include "RummyTable.h"
#include "Exceptions.h"


RummyTable::RummyTable() {}

RummyTable::~RummyTable() {
  for (auto & v : table) {
    for (auto & c : v)
      delete c;
  }
}

void RummyTable::addMeld(std::vector<Card*> meld) {
  if (validateMeld(meld))
    table.push_back(meld);
  else
    throw unmet_precondition_error("Meld is not valid");
}

void RummyTable::addCard(Card* c) {
  for (auto & v : table) {
    if (isSet(v)) {
      if (v.back()->rank == c->rank) {
          v.push_back(c);
          return;
      }
    } else {
      if (v.front()->suit != c->suit)
          continue;

      if (v.front()->rank - 1 == c->rank) {
        v.insert(v.begin(), c);
        return;
      } else if (v.back()->rank + 1 == c->rank) {
        v.push_back(c);
        return;
      }
    }
  }
  throw unmet_precondition_error("That card cannot be added to any melds");
}

const std::vector<std::vector<Card*>>& RummyTable::getMelds() {
  return table;
}

std::vector<Card*> RummyTable::takeAllCards() {
  std::vector<Card*> cards;
  for (auto & v : table) {
    for (auto c : v) {
      cards.push_back(c);
    }
  }
  table.clear();
  return cards;
}

bool RummyTable::isSet(const std::vector<Card*>& meld) {
  Card* lastCard = meld.at(0);
  for (unsigned int i = 1; i < meld.size(); i++) {
    if (meld.at(i)->rank != lastCard->rank)
      return false;
    lastCard = meld.at(i);
  }
  return true;
}

bool isRun(const std::vector<Card*> meld) {
  Card* lastCard = meld.at(0);
  Card::Suit suit = lastCard->suit;
  for (unsigned int i = 1; i < meld.size(); i++) {
    Card* c = meld.at(i);
    if (c->rank - 1 != lastCard->rank || c->suit != suit)
      return false;
    lastCard = c;
  }
  return true;
}

bool RummyTable::validateMeld(const std::vector<Card*>& meld) {
  if (meld.size() < 3)
    return false;

  if (isSet(meld) || isRun(meld))
    return true;

  return false;
}
