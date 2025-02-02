#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include "RummyUI.h"
#include "Player.h"
#include "Card.h"


RummyUI::RummyUI() {}

RummyUI::~RummyUI() {}

void RummyUI::takeTurn(Player* p) {
  std::cout << "======= " << p->name << "'s Turn ========\n" << std::endl;
}

void RummyUI::displayTable(RummyTable* table) {
  std::cout << "--- The Table ---" << std::endl;
  if (table->getMelds().size()) {
    for (auto & v : table->getMelds()) {
      for (auto c : v)
        std::cout << *c << " ";
      std::cout << std::endl;
    }
  } else {
    std::cout << "Empty" << std::endl;
  }
  std::cout << std::endl;
}

void RummyUI::displayHand(std::list<Card*>* hand) {
  std::cout << "-- Your Hand (size = " << hand->size() << "):" << std::endl;
  for (auto it = hand->begin(); it != hand->end(); it++)
      std::cout << *(*it) << " ";
  std::cout << std::endl << std::endl;
}

int RummyUI::drawFromDeck(RummyDeck* deck) {
  int choice = 0;
  bool empty = deck->size() == 0;

  if (!empty) {
    std::cout << "Draw from the deck or the discard?" << std::endl;
    std::cout << "1. Deck(" << deck->size() << ")" << std::endl;
  } else {
    std::cout << "Draw from the deck or the discard?" << std::endl;
    std::cout << "1. Flip over discard and take card" << std::endl;
  }

  std:: cout << "2. Discard -> ";
  std::cout << *(deck->topDiscard()) << std::endl;

  while (1) {
    std::cout << "Choice? ";

    std::cin >> choice;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        continue;
    }

    std::cout << std::endl;
    if (choice > 2 || choice < 1) {
      continue;
    } else if (choice == 1 && empty) {
      return 3;  // flip discard
    } else {
      return choice;
    }
  }
}

void RummyUI::pickedCard(Card* c) {
  std::cout << "*** You Picked up " << *c <<" ***" << std::endl << std::endl;
}

std::vector<int> RummyUI::playMeld(std::list<Card*>* hand) {
  std::cout << "-- Play Melds --" << std::endl;
  std::cout << "Enter the positions of the cards (0 to skip): " << std::endl;

  std::vector<int> idxs;
  int i;
  std::string in;
  std::cin.ignore();
  std::getline(std::cin, in);

  std::stringstream ss(in);
  while (ss >> i) {
    if (i == 0) {
        idxs.clear();
        break;
    }
    idxs.push_back(i);
  }
  std::cout << std::endl;
  return idxs;
}

int RummyUI::layOff(std::list<Card*>* hand) {
  std::cout << "-- LayOff --" << std::endl;
  std::cout << "Will be added to first available meld!(0 to skip)" << std::endl;

  while (1) {
    std::cout << "Enter the position of card to place on table: " << std::endl;

    int i;
    std::cin >> i;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        continue;
    }

    if (i >= 0 && i <= hand->size()) {
      std::cout << std::endl;
      return i;
    }
  }
}

void RummyUI::turnOver(Player* player) {
  std::cout << "** Your turn is over **" << std::endl;
  std::cout << "Press ENTER To Continue ...";
  std::cout << std::endl;
  std::string in;
  std::cin.ignore();
  std::getline(std::cin, in);
}


unsigned int RummyUI::requestCard(Player* player,
                               std::list<Card*>* hand) {
  if (!hand->size())
    return 42;

  displayHand(hand);
  while (1) {
    std::cout << "Position of card to discard: ";

    int i;
    std::cin >> i;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        continue;
    }

    if (i > 0 && i <= hand->size()) {
      std::cout << std::endl;
      return i - 1;
    }
  }
}

void RummyUI::playFailed() {
  std::cout << "Sorry that play was invalid!" << std::endl << std::endl;
}

void RummyUI::playSucceeded() {
  std::cout << "Well played!" << std::endl << std::endl;;
}

void RummyUI::showGameOutcome(std::vector<Player*> players) {
  std::cout << "-- Points for the Losers --" << std::endl;
  for (auto & p : players)
    std::cout << p->name << ": " << p->getScore() << " pts";
    std::cout << std::endl;
}

void RummyUI::outOfGame(Player* player) {
  std::cout << "====== Game Over =======" << std::endl << std::endl;
  std::cout << player->name << " WINS!!!!" << std::endl;
}
