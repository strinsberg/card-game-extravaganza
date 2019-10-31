#include "OldMaidUI.h"
#include <iostream>
#include <vector>
#include <list>

unsigned int OldMaidUI::requestCard(Player* p, std::list<Card*>* hand) {
    std::cout << p->name << " it is your turn." << std::endl;

    bool valid;
    unsigned int selection;
    do {
        valid = true;
        std::cout << "Choose a card [1 - " << hand->size() << "]: ";
        std::cin >> selection;
        if (selection < 1 || selection > hand->size()) {
            std::cerr << "Not a valid choice. ";
            std::cerr << "Please choose again." << std::endl;
            valid = false;
        }
    } while (!valid);

    return selection-1;
}

void OldMaidUI::playFailed() {
    std::cout << "Sorry, no match." << std::endl << std::endl;
}

void OldMaidUI::playSucceeded() {
    std::cout << "You got a match!" << std::endl << std::endl;
}

void OldMaidUI::outOfGame(Player* player) {
    std::cout << "Congratulations, " << player->name
              << "! You are out of cards." << std::endl << std::endl;
}

void OldMaidUI::showGameOutcome(std::vector<Player*> players) {
    std::cout << players[0]->name << " loses!" << std::endl;
}
