#include "Player.h"
#include <iostream>
#include <list>

Player::~Player() {
    for (unsigned int i = 0; i < hand.size(); ++i)
        delete hand.front();
    hand.clear();
}

void Player::addCard(Card* c) {
    hand.push_back(c);
}

std::list<Card*>* Player::getHand() {
    return &hand;
}

Card* Player::getCard(unsigned int index) {
    if (index >= hand.size())
        return nullptr;

    std::list<Card*>::iterator card;
    unsigned int count = 0;
    for (card = hand.begin(); card != hand.end() && count < index; ++card) {
        count++;
    }
    return *card;
}
