#include <iostream>
#include <list>
#include <vector>
#include "RummyUI.h"
#include "Player.h"
#include "Card.h"


RummyUI::RummyUI() {}
RummyUI::~RummyUI() {}
void RummyUI::takeTurn(Player* p) {}
void RummyUI::displayTable(RummyTable* table) {}
void RummyUI::displayHand(std::list<Card*>* hand) {}
bool RummyUI::drawFromDeck() {}
void RummyUI::playMeld(std::list<Card*>* hand) {}
void RummyUI::layOff(std::list<Card*>* hand) {}

unsigned int RummyUI::requestCard(Player* player,
                               std::list<Card*>* hand) {
}

void RummyUI::playFailed() {
}

void RummyUI::playSucceeded() {
}

void RummyUI::showGameOutcome(std::vector<Player*> players) {
}

void RummyUI::outOfGame(Player* player) {
}
