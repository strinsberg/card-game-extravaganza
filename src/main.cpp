#include <iostream>
#include <string>
#include "OldMaidUI.h"
#include "OldMaid.h"
#include "OldMaidDeck.h"
#include "Game.h"
#include "Rummy.h"
#include "RummyDeck.h"
#include "RummyUI.h"

const char* players[] = {"Wendy", "John", "Barry", "Silvan"};

int main() {
    // Ask which game to play
    int game;

    std::cout << "Welcome to the card Game extravaganza!!!\n\n";
    std::cout << "What game would you like to play?\n";
    std::cout << "1. Rummy\n2. Old Maid\n";
    std::cout << "Choice: ";

    std::cin >> game;
    if (std::cin.fail()) {
      std::cout << "Not a valid Choice!!\nBetter luck next time!\n";
      return 0;
    }
    std::cout << std::endl;

    // Build game objects
    Game* g;
    if (game == 1) {
      RummyDeck* rd = new RummyDeck();
      rd->create();
      RummyUI* rui = new RummyUI();
      g = new Rummy(rui, rd);

    } else if (game == 2) {
      OldMaidDeck* omd = new OldMaidDeck();
      omd->create();
      OldMaidUI* omui = new OldMaidUI();
      g = new OldMaid(omui, omd);

    } else {
      std::cout << "Not a valid Choice!!\nBetter luck next time!\n";
      return 0;
    }

    // Ask for players
    std::string name;
    std::cout << "What is your name (one word)? ";
    std::cin >> name;
    std::cout << std::endl;

    int playerNum = 10;
    while (playerNum > 3 || playerNum < 0) {
      std::cout << "How many opponents (1-3)? ";
      std::cin >> playerNum;
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        continue;
      }
    }
    std::cout << std::endl;

    g->addPlayer(new Player(name));
    for (int i = 0; i < playerNum; i++)
      g->addPlayer(new Player(players[i]));

    // Start game
    g->start();

    std::cout << "\nThanks for playing!\n\n";

    delete g;

    return 0;
}
