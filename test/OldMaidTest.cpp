#include <vector>
#include "gtest/gtest.h"
#include "MockOldMaidDeck.h"
#include "MockUI.h"
#include "Card.h"
#include "OldMaid.h"

unsigned int cards = 49;
ACTION(GetCardCount) {
    return cards--;
}

TEST(OldMaid, CardDeal) {
    MockOMDeck d;


    EXPECT_CALL(d, getCard())
    .Times(cards)
    .WillRepeatedly(testing::Return(new Card(Card::CLUB, Card::ACE)));


    EXPECT_CALL(d, size())
    .Times(1)
    .WillRepeatedly(GetCardCount());


    MockUI ui;

    Game* game = new OldMaid(&ui, &d);

    game->addPlayer(new Player("John"));
    game->addPlayer(new Player("Danielle"));

    std::vector<Player*> players = game->getPlayers();
    game->dealCards(players);

    EXPECT_EQ((cards/2)+1, players.at(0)->getHand()->size());
    EXPECT_EQ((cards/2), players.at(1)->getHand()->size());
}

TEST(OldMaid, SmallGame) {
    MockOMDeck d;

    testing::Expectation shuffled = EXPECT_CALL(d, shuffle()).Times(1);

    EXPECT_CALL(d, size())
    .Times(1)
    .WillOnce(testing::Return(3));

    EXPECT_CALL(d, getCard())
    .Times(3)
    .After(shuffled)
    // Deck
    .WillOnce(testing::Return(new Card(Card::CLUB, Card::QUEEN)))
    .WillOnce(testing::Return(new Card(Card::CLUB, Card::ACE)))
    .WillOnce(testing::Return(new Card(Card::SPADE, Card::ACE)));

    MockUI ui;

    EXPECT_CALL(ui, requestCard(testing::_, testing::_))
    .Times(2)
    .WillRepeatedly(testing::Return(0));

    EXPECT_CALL(ui, playSucceeded())
    .Times(1);

    EXPECT_CALL(ui, playFailed())
    .Times(1);

    EXPECT_CALL(ui, outOfGame(testing::_))
    .Times(1);

    Game* game = new OldMaid(&ui, &d);

    Player* player1 =  new Player("John");
    Player* player2 = new Player("Kira");

    game->addPlayer(player1);
    game->addPlayer(player2);

    game->start();

    EXPECT_EQ(0, player1->getHand()->size());
    EXPECT_EQ(1, player2->getHand()->size());

    Card* c = player2->getCard(0);
    EXPECT_EQ(Card::QUEEN, c->rank);
}
