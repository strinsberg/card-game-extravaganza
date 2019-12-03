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
  // setup rummy
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);
  
  Player* p = new Player("Steve");
  r.addPlayer(p);

  Card* c = new Card(Card::Suit::SPADE, Card::Rank::ACE);

  EXPECT_CALL(*mUI, takeTurn(p))
  .Times(1);

  EXPECT_CALL(*mUI, displayTable(testing::_))
  .Times(1);

  EXPECT_CALL(*mUI, displayHand(p->getHand()))
  .Times(1);

  EXPECT_CALL(*mUI, drawFromDeck(mDeck))
  .Times(1)
  .WillOnce(testing::Return(0));

  EXPECT_CALL(*mDeck, flipDiscard())
  .Times(1);

  EXPECT_CALL(*mDeck, getCard())
  .Times(1)
  .WillOnce(testing::Return(c));

  std::vector<int> empty;

  EXPECT_CALL(*mUI, playMeld(p->getHand()))
  .Times(1)
  .WillOnce(testing::Return(empty));

  EXPECT_CALL(*mUI, layOff(p->getHand()))
  .Times(1)
  .WillOnce(testing::Return(0));

  r.beforeTurn(0, 1);
}

TEST(RummyTests, displayTurn) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);
  
  Player* p = new Player("Steve");
  r.addPlayer(p);

  EXPECT_CALL(*mUI, takeTurn(p))
  .Times(1);

  EXPECT_CALL(*mUI, displayTable(testing::_))
  .Times(1);

  r.displayTurnInfo(p);
}

TEST(RummyTests, displayHand) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);
  
  Player* p = new Player("Steve");
  r.addPlayer(p);

  EXPECT_CALL(*mUI, displayHand(p->getHand()))
  .Times(1);

  r.displayHand(p);
}

TEST(RummyTests, pickupCard) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);
  
  Player* p = new Player("Steve");
  r.addPlayer(p);

  Card* c = new Card(Card::Suit::SPADE, Card::Rank::ACE);
  Card* c2 = new Card(Card::Suit::SPADE, Card::Rank::ACE);
  Card* c3 = new Card(Card::Suit::SPADE, Card::Rank::ACE);

  EXPECT_CALL(*mUI, drawFromDeck(mDeck))
  .Times(3)
  .WillOnce(testing::Return(1))
  .WillOnce(testing::Return(2))
  .WillOnce(testing::Return(0));

  EXPECT_CALL(*mDeck, getCard())
  .Times(2)
  .WillOnce(testing::Return(c))
  .WillOnce(testing::Return(c2));

  EXPECT_CALL(*mDeck, takeDiscardTop())
  .Times(1)
  .WillOnce(testing::Return(c3));

  EXPECT_CALL(*mDeck, flipDiscard())
  .Times(1);

  r.pickupCard(p);
  r.pickupCard(p);
  r.pickupCard(p);

  EXPECT_EQ(3, p->getHand()->size());
}

TEST(RummyTests, playMeld_invalid) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);
  
  Player* p = new Player("Steve");
  r.addPlayer(p);
  p->addCard(new Card(Card::Suit::SPADE, Card::Rank::ACE));
  p->addCard(new Card(Card::Suit::SPADE, Card::Rank::TWO));
  p->addCard(new Card(Card::Suit::SPADE, Card::Rank::KING));

  std::vector<int> meldIdxs{1,2,3};
  std::vector<int> empty;

  EXPECT_CALL(*mUI, playMeld(p->getHand()))
  .Times(2)
  .WillOnce(testing::Return(meldIdxs))
  .WillOnce(testing::Return(empty));

  EXPECT_CALL(*mUI, playFailed())
  .Times(1);

  r.playMelds(p);
  EXPECT_EQ(3, p->getHand()->size());
}

TEST(RummyTests, playMeld_valid_layoff_valid) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);
  
  Player* p = new Player("Steve");
  r.addPlayer(p);
  p->addCard(new Card(Card::Suit::SPADE, Card::Rank::ACE));
  p->addCard(new Card(Card::Suit::SPADE, Card::Rank::TWO));
  p->addCard(new Card(Card::Suit::SPADE, Card::Rank::THREE));
  p->addCard(new Card(Card::Suit::SPADE, Card::Rank::FOUR));

  std::vector<int> meldIdxs{1,2,3};
  std::vector<int> empty;

  EXPECT_CALL(*mUI, playMeld(p->getHand()))
  .Times(2)
  .WillOnce(testing::Return(meldIdxs))
  .WillOnce(testing::Return(empty));

  r.playMelds(p);
  EXPECT_EQ(1, p->getHand()->size());

  EXPECT_CALL(*mUI, layOff(p->getHand()))
  .Times(2)
  .WillOnce(testing::Return(1))
  .WillOnce(testing::Return(0));

  r.layOff(p);
  EXPECT_EQ(0, p->getHand()->size());
}

TEST(RummyTests, layOff_invalid) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);
  
  Player* p = new Player("Steve");
  r.addPlayer(p);
  p->addCard(new Card(Card::Suit::SPADE, Card::Rank::ACE));
  p->addCard(new Card(Card::Suit::SPADE, Card::Rank::TWO));
  p->addCard(new Card(Card::Suit::SPADE, Card::Rank::KING));

  EXPECT_CALL(*mUI, layOff(p->getHand()))
  .Times(2)
  .WillOnce(testing::Return(1))
  .WillOnce(testing::Return(0));

  EXPECT_CALL(*mUI, playFailed())
  .Times(1);

  r.layOff(p);
  EXPECT_EQ(3, p->getHand()->size());
}

TEST(RummyTests, turnOver) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);

  EXPECT_TRUE(r.turnOver());
}

TEST(RummyTests, afterTurn) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);

  Player* p = new Player("Steve");
  Card* c = new Card(Card::Suit::SPADE, Card::Rank::ACE);
  p->addCard(c);
  r.addPlayer(p);

  EXPECT_CALL(*mUI, turnOver(p))
  .Times(1);

  std::vector<Player*> players = r.getPlayers();
  r.afterTurn(p, &players, c);

  EXPECT_EQ(0, p->getHand()->size());
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

TEST(TestRummy, sortHand) {
  MockRummyUI* mUI = new MockRummyUI();
  MockRummyDeck* mDeck = new MockRummyDeck();
  Rummy r(mUI, mDeck);
 
  std::list<Card*> hand;
  hand.push_back(new Card(Card::Suit::SPADE, Card::Rank::KING));
  hand.push_back(new Card(Card::Suit::HEART, Card::Rank::TEN));
  hand.push_back(new Card(Card::Suit::CLUB, Card::Rank::KING));
  hand.push_back(new Card(Card::Suit::DIAMOND, Card::Rank::SEVEN));
  hand.push_back(new Card(Card::Suit::SPADE, Card::Rank::ACE));
  hand.push_back(new Card(Card::Suit::HEART, Card::Rank::TWO));

  r.sortHand(&hand);

  Card* c;
  
  c = hand.front();
  hand.pop_front();
  EXPECT_EQ(Card::Suit::CLUB, c->suit);
  EXPECT_EQ(Card::Rank::KING, c->rank);
  delete c;

  c = hand.front();
  hand.pop_front();
  EXPECT_EQ(Card::Suit::DIAMOND, c->suit);
  EXPECT_EQ(Card::Rank::SEVEN, c->rank);
  delete c;

  c = hand.front();
  hand.pop_front();
  EXPECT_EQ(Card::Suit::SPADE, c->suit);
  EXPECT_EQ(Card::Rank::ACE, c->rank);
  delete c;

  c = hand.front();
  hand.pop_front();
  EXPECT_EQ(Card::Suit::SPADE, c->suit);
  EXPECT_EQ(Card::Rank::KING, c->rank);
  delete c;

  c = hand.front();
  hand.pop_front();
  EXPECT_EQ(Card::Suit::HEART, c->suit);
  EXPECT_EQ(Card::Rank::TWO, c->rank);
  delete c;

  c = hand.front();
  hand.pop_front();
  EXPECT_EQ(Card::Suit::HEART, c->suit);
  EXPECT_EQ(Card::Rank::TEN, c->rank);
  delete c;
}
