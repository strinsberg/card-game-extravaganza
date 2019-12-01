#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Rummy.h"
#include "Card.h"
#include "Player.h"
#include "MockRummyUI.h"
#include "MockRummyDeck.h"

TEST(RummyTests, countPoints) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);

  Player p("Batman");
  p.addCard(new Card(Card::Suit::HEART, Card::Rank::ACE));
  p.addCard(new Card(Card::Suit::HEART, Card::Rank::TWO));
  p.addCard(new Card(Card::Suit::HEART, Card::Rank::THREE));
  p.addCard(new Card(Card::Suit::HEART, Card::Rank::FOUR));
  p.addCard(new Card(Card::Suit::HEART, Card::Rank::FIVE));
  p.addCard(new Card(Card::Suit::HEART, Card::Rank::SIX));
  p.addCard(new Card(Card::Suit::HEART, Card::Rank::SEVEN));
  p.addCard(new Card(Card::Suit::HEART, Card::Rank::EIGHT));
  p.addCard(new Card(Card::Suit::HEART, Card::Rank::NINE));
  p.addCard(new Card(Card::Suit::HEART, Card::Rank::TEN));
  p.addCard(new Card(Card::Suit::HEART, Card::Rank::JACK));
  p.addCard(new Card(Card::Suit::HEART, Card::Rank::QUEEN));
  p.addCard(new Card(Card::Suit::HEART, Card::Rank::KING));

  EXPECT_EQ(85, r.countPoints(&p));
}

TEST(RummyTests, beforeTurn) {
}

TEST(RummyTests, afterTurn) {
}

TEST(RummyTests, turnOver) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);

  EXPECT_TRUE(r.turnOver());
}

TEST(RummyTests, isOver_true) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);

  Player* p = new Player("Francis");

  EXPECT_CALL(*mUI, outOfGame(p))
  .Times(1);

  r.addPlayer(p);
  r.checkIfPlayerOut();

  EXPECT_TRUE(r.isOver());
}

TEST(RummyTests, isOver_false) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);

  EXPECT_FALSE(r.isOver());
}

TEST(RummyTests, dealCards_two_players) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);

  Player* p = new Player("Stan");
  Player* p2 = new Player("Betty");
  r.addPlayer(p);
  r.addPlayer(p2);

  EXPECT_CALL(*mDeck, getCard())
  .Times(20)
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::ACE)))
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::TWO)))
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::THREE)))
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::FOUR)))
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::FIVE)))
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::SIX)))
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::SEVEN)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::ACE)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::TWO)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::THREE)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::FOUR)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::FIVE)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::SIX)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::SEVEN)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::EIGHT)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::NINE)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::TEN)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::JACK)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::QUEEN)))
  .WillOnce(testing::Return(new Card(Card::Suit::CLUB, Card::Rank::KING)));

  r.dealCards(r.getPlayers());
  EXPECT_EQ(10, p->getHand()->size());
  EXPECT_EQ(10, p2->getHand()->size());
}


TEST(RummyTests, dealCards_three_players) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);

  Player* p = new Player("Stan");
  Player* p2 = new Player("Betty");
  Player* p3 = new Player("Betty");
  r.addPlayer(p);
  r.addPlayer(p2);
  r.addPlayer(p3);

  EXPECT_CALL(*mDeck, getCard())
  .Times(21)
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::ACE)))
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::TWO)))
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::THREE)))
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::FOUR)))
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::FIVE)))
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::SIX)))
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::SEVEN)))
  .WillOnce(testing::Return(new Card(Card::Suit::SPADE, Card::Rank::EIGHT)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::ACE)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::TWO)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::THREE)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::FOUR)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::FIVE)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::SIX)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::SEVEN)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::EIGHT)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::NINE)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::TEN)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::JACK)))
  .WillOnce(testing::Return(new Card(Card::Suit::HEART, Card::Rank::QUEEN)))
  .WillOnce(testing::Return(new Card(Card::Suit::CLUB, Card::Rank::KING)));

  r.dealCards(r.getPlayers());
  EXPECT_EQ(7, p->getHand()->size());
  EXPECT_EQ(7, p2->getHand()->size());
  EXPECT_EQ(7, p3->getHand()->size());
}
