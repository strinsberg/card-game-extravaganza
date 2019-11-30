#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <vector>
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
  Card* c = new Card(Card::Suit::HEART, Card::Rank::ACE);
  Card* c2 = new Card(Card::Suit::HEART, Card::Rank::TWO);
  Card* c3 = new Card(Card::Suit::HEART, Card::Rank::THREE);
  meld.emplace_back(c);
  meld.emplace_back(c2);
  meld.emplace_back(c3);

  Card* c4 = new Card(Card::Suit::HEART, Card::Rank::FOUR);
  rt.addMeld(meld);
  rt.addCard(c4);
  EXPECT_EQ(4, rt.getMelds().at(0).size());

  for (auto & c : meld)
      delete c;
  delete c4;
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

  Card* c4 = new Card(Card::Suit::HEART, Card::Rank::FOUR);
  rt.addMeld(meld);
  EXPECT_THROW(rt.addCard(c4), unmet_precondition_error);
  EXPECT_EQ(3, rt.getMelds().at(0).size());

  for (auto & c : meld)
      delete c;
  delete c4;
}
