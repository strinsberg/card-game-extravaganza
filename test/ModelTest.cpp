#include "gtest/gtest.h"
#include "OldMaid.h"
#include "Exceptions.h"

TEST(Game, EmptyGame) {
    Game* game = new OldMaid(nullptr, nullptr);
    EXPECT_THROW(game->start(), game_init_error);
}

TEST(Player, GetCard) {
    Player* p = new Player("Test");
    p->addCard(new Card(Card::SPADE, Card::ACE));
    p->addCard(new Card(Card::SPADE, Card::KING));

    EXPECT_NE(p->getCard(1), nullptr);
    EXPECT_EQ(p->getCard(2), nullptr);
}
