#include <vector>
#include "Rummy.h"
#include "RummyDeck.h"
#include "GameUI.h"
#include "Card.h"
#include "Player.h"


Rummy::Rummy(GameUI* ui, RummyDeck* deck) : Game(ui, deck), rummyDeck(deck) {
}

Rummy::~Rummy() {
}

int Rummy::countPoints(Player*) {
}

void Rummy::dealCards(std::vector<Player*> p) {
}

void Rummy::beforeTurn(unsigned int playerNum,
                      unsigned int numPlayers) {
}

void Rummy::afterTurn(Player* currentPlayer, std::vector<Player*>* players,
                     Card* played) {
}

bool Rummy::turnOver() {
}

bool Rummy::isOver() {
}
