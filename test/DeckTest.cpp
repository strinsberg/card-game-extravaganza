#include <iostream>
#include "gtest/gtest.h"
#include "Deck.h"
#include "OldMaidDeck.h"

TEST(Deck, DeckSize) {
    Deck d;
    d.create();
    EXPECT_EQ(52, d.size());
}

TEST(Deck, DeckCard) {
    Deck d;
    d.create();
    EXPECT_EQ(52, d.size());
    d.getCard();
    EXPECT_EQ(51, d.size());
}


TEST(Deck, DeckShuffle) {
    Deck d1;
    d1.create();
    Card* c = d1.getCard();
    EXPECT_EQ(Card::CLUB, c->suit);
    EXPECT_EQ(Card::ACE, c->rank);

    Deck d2;
    d2.create();
    d2.shuffle();
    c = d2.getCard();

    EXPECT_FALSE(Card::CLUB == c->suit && Card::ACE == c->rank);
}

TEST(Deck, DeckEmpty) {
    Deck d;
    unsigned int deckSize = d.size();
    for (unsigned int i=0; i < deckSize; i++) {
        d.getCard();
    }

    EXPECT_TRUE(d.getCard() == nullptr);
    EXPECT_TRUE(d.getCard() == nullptr);
}

TEST(OldMaidDeck, DeckSize) {
    OldMaidDeck d;
    d.create();
    EXPECT_EQ(49, d.size());
}

TEST(OldMaidDeck, OneQueen) {
    OldMaidDeck d;
    d.create();
    unsigned int numQueens = 0;
    while (d.size() > 0) {
        Card* card = d.getCard();
        if (card->rank == Card::QUEEN)
            ++numQueens;
    }
    EXPECT_EQ(1, numQueens);
}
