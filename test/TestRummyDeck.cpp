#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "RummyDeck.h"
#include "Card.h"

TEST(TestRummyDeck, deck_top_discard) {
  RummyDeck rd;
  rd.create();

  rd.discardDeckTop();
  Card *c = rd.topDiscard();
  EXPECT_EQ(Card::Rank::ACE, c->rank);
  EXPECT_EQ(Card::Suit::CLUB, c->suit);
  EXPECT_EQ(51, rd.size());

  delete c;
}

TEST(TestRummyDeck, deck_take_discard_top) {
  RummyDeck rd;
  rd.create();

  rd.discardDeckTop();
  Card *c = rd.takeDiscardTop();

  EXPECT_EQ(Card::Rank::ACE, c->rank);
  EXPECT_EQ(Card::Suit::CLUB, c->suit);
  EXPECT_EQ(0, rd.discardSize());

  delete c;
}

TEST(TestRummyDeck, deck_take_discard_top_empty) {
  RummyDeck rd;
  rd.create();

  Card *c = rd.takeDiscardTop();

  EXPECT_EQ(nullptr, c);

  delete c;
}
