#include <iostream>
#include <list>
#include <vector>
#include "RummyUI.h"
#include "Player.h"
#include "Card.h"


RummyUI::RummyUI() {}
RummyUI::~RummyUI() {}

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
