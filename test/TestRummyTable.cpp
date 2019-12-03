#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "RummyTable.h"
#include "Card.h"
#include "Exceptions.h"


TEST(TestRummyTable, addMeld) {
  RummyTable rt;

  std::vector<Card*> meld;
  Card* c = new Card(Card::Suit::HEART, Card::Rank::ACE);
  Card* c2 = new Card(Card::Suit::HEART, Card::Rank::TWO);
  Card* c3 = new Card(Card::Suit::HEART, Card::Rank::THREE);
  meld.emplace_back(c);
  meld.emplace_back(c2);
  meld.emplace_back(c3);

  rt.addMeld(meld);
  EXPECT_EQ(1, rt.getMelds().size());

  for (auto & c : meld)
      delete c;
}

TEST(TestRummyTable, addCard_set) {
  RummyTable rt;

  std::vector<Card*> meld;
  Card* c = new Card(Card::Suit::HEART, Card::Rank::ACE);
  Card* c2 = new Card(Card::Suit::SPADE, Card::Rank::ACE);
  Card* c3 = new Card(Card::Suit::CLUB, Card::Rank::ACE);
  meld.emplace_back(c);
  meld.emplace_back(c2);
  meld.emplace_back(c3);

  Card* c4 = new Card(Card::Suit::DIAMOND, Card::Rank::ACE);
  rt.addMeld(meld);
  rt.addCard(c4);
  EXPECT_EQ(4, rt.getMelds().at(0).size());

  for (auto & c : meld)
      delete c;
  delete c4;
}

TEST(TestRummyTable, addCard_run) {
  RummyTable rt;

  std::vector<Card*> meld;
  Card* c = new Card(Card::Suit::HEART, Card::Rank::TWO);
  Card* c2 = new Card(Card::Suit::HEART, Card::Rank::THREE);
  Card* c3 = new Card(Card::Suit::HEART, Card::Rank::FOUR);
  meld.emplace_back(c);
  meld.emplace_back(c2);
  meld.emplace_back(c3);

  Card* c4 = new Card(Card::Suit::HEART, Card::Rank::FIVE);
  Card* c5 = new Card(Card::Suit::HEART, Card::Rank::ACE);
  rt.addMeld(meld);
  rt.addCard(c4);
  rt.addCard(c5);
  EXPECT_EQ(5, rt.getMelds().at(0).size());

  for (auto & c : meld)
      delete c;
  delete c4;
  delete c5;
}

TEST(TestRummyTable, addCard_throws_set) {
  RummyTable rt;

  std::vector<Card*> meld;
  Card* c = new Card(Card::Suit::HEART, Card::Rank::ACE);
  Card* c2 = new Card(Card::Suit::SPADE, Card::Rank::ACE);
  Card* c3 = new Card(Card::Suit::CLUB, Card::Rank::ACE);
  meld.emplace_back(c);
  meld.emplace_back(c2);
  meld.emplace_back(c3);

  Card* c4 = new Card(Card::Suit::HEART, Card::Rank::KING);
  rt.addMeld(meld);
  EXPECT_THROW(rt.addCard(c4), unmet_precondition_error);
  EXPECT_EQ(3, rt.getMelds().at(0).size());

  for (auto & c : meld)
      delete c;
  delete c4;
}

TEST(TestRummyTable, addCard_throws_run) {
  RummyTable rt;

  std::vector<Card*> meld;
  Card* c = new Card(Card::Suit::HEART, Card::Rank::ACE);
  Card* c2 = new Card(Card::Suit::HEART, Card::Rank::TWO);
  Card* c3 = new Card(Card::Suit::HEART, Card::Rank::THREE);
  meld.emplace_back(c);
  meld.emplace_back(c2);
  meld.emplace_back(c3);

  Card* c4 = new Card(Card::Suit::HEART, Card::Rank::SIX);
  Card* c5 = new Card(Card::Suit::SPADE, Card::Rank::FOUR);
  rt.addMeld(meld);
  EXPECT_THROW(rt.addCard(c4), unmet_precondition_error);
  EXPECT_THROW(rt.addCard(c5), unmet_precondition_error);
  EXPECT_EQ(3, rt.getMelds().at(0).size());

  for (auto & c : meld)
      delete c;
  delete c4;
  delete c5;
}

TEST(TestRummyTable, takeAllCards) {
  RummyTable rt;

  std::vector<Card*> meld;
  Card* c = new Card(Card::Suit::HEART, Card::Rank::ACE);
  Card* c2 = new Card(Card::Suit::HEART, Card::Rank::TWO);
  Card* c3 = new Card(Card::Suit::HEART, Card::Rank::THREE);
  meld.emplace_back(c);
  meld.emplace_back(c2);
  meld.emplace_back(c3);

  std::vector<Card*> meld2;
  Card* c4 = new Card(Card::Suit::DIAMOND, Card::Rank::ACE);
  Card* c5 = new Card(Card::Suit::SPADE, Card::Rank::ACE);
  Card* c6 = new Card(Card::Suit::CLUB, Card::Rank::ACE);
  meld2.emplace_back(c4);
  meld2.emplace_back(c5);
  meld2.emplace_back(c6);

  rt.addMeld(meld);
  rt.addMeld(meld2);
  std::vector<Card*> cards = rt.takeAllCards();

  EXPECT_EQ(c, cards.at(0));
  EXPECT_EQ(c2, cards.at(1));
  EXPECT_EQ(c3, cards.at(2));
  EXPECT_EQ(c4, cards.at(3));
  EXPECT_EQ(c5, cards.at(4));
  EXPECT_EQ(c6, cards.at(5));

  EXPECT_EQ(6, cards.size());
  EXPECT_EQ(0, rt.getMelds().size());

  for (auto & c : cards)
      delete c;
}

TEST(TestRummyTable, validateMeld_set) {
  RummyTable rt;

  Card* c1 = new Card(Card::Suit::SPADE, Card::Rank::ACE);
  Card* c2 = new Card(Card::Suit::HEART, Card::Rank::ACE);
  Card* c3 = new Card(Card::Suit::CLUB, Card::Rank::ACE);

  std::vector<Card*> meld{c1, c2, c3};
  EXPECT_TRUE(rt.validateMeld(meld));
}

TEST(TestRummyTable, validateMeld_run) {
  RummyTable rt;

  Card* c1 = new Card(Card::Suit::SPADE, Card::Rank::ACE);
  Card* c2 = new Card(Card::Suit::SPADE, Card::Rank::TWO);
  Card* c3 = new Card(Card::Suit::SPADE, Card::Rank::THREE);

  std::vector<Card*> meld{c1, c2, c3};
  EXPECT_TRUE(rt.validateMeld(meld));
}


TEST(TestRummyTable, validateMeld_set_throws) {
  RummyTable rt;

  Card* c1 = new Card(Card::Suit::SPADE, Card::Rank::ACE);
  Card* c2 = new Card(Card::Suit::HEART, Card::Rank::ACE);
  Card* c3 = new Card(Card::Suit::SPADE, Card::Rank::FOUR);

  std::vector<Card*> meld{c1, c2, c3};
  EXPECT_FALSE(rt.validateMeld(meld));
}

TEST(TestRummyTable, validateMeld_run_throws_not_in_row) {
  RummyTable rt;

  Card* c1 = new Card(Card::Suit::SPADE, Card::Rank::ACE);
  Card* c2 = new Card(Card::Suit::SPADE, Card::Rank::TWO);
  Card* c3 = new Card(Card::Suit::SPADE, Card::Rank::FOUR);

  std::vector<Card*> meld{c1, c2, c3};
  EXPECT_FALSE(rt.validateMeld(meld));
}

TEST(TestRummyTable, validateMeld_runs_throws_not_same_suit) {
  RummyTable rt;

  Card* c1 = new Card(Card::Suit::SPADE, Card::Rank::ACE);
  Card* c2 = new Card(Card::Suit::SPADE, Card::Rank::TWO);
  Card* c3 = new Card(Card::Suit::HEART, Card::Rank::THREE);

  std::vector<Card*> meld{c1, c2, c3};
  EXPECT_FALSE(rt.validateMeld(meld));
}
