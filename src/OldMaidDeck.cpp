#include "OldMaidDeck.h"
#include <vector>

void OldMaidDeck::create() {
    Deck::create();

    // Remove three Queens
    std::vector<Card*>::iterator card;
    std::vector<Card*> toRemove;
    for (card = deck.begin(); card != deck.end(); ++card) {
        if ((*card)->rank == Card::Rank::QUEEN) {
            if (toRemove.size() < 3)
                toRemove.push_back(*card);
        }
    }

    if (toRemove.size() > 0) {
        for (std::vector<Card*>::iterator card = toRemove.begin();
                card != toRemove.end();
                ++card) {
            std::vector<Card*>::iterator it = deck.begin();
            while (it != deck.end()) {
                if (*it == *card) {
                    Card* toDelete = *it;
                    deck.erase(it);
                    delete toDelete;
                    break;
                }
                ++it;
            }
        }
    }
}
