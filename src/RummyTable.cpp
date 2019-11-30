#include "RummyTable.h"
#include "Exceptions.h"


RummyTable::RummyTable() {}

RummyTable::~RummyTable() {}

void RummyTable::addMeld(std::vector<Card*> meld) {
    table.push_back(meld);
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
  return std::vector<Card*>();
}

bool RummyTable::isSet(const std::vector<Card*>& meld) {
  if (meld.at(0)->rank == meld.at(1)->rank)
    return true;
  return false;
}
