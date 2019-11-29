#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "RummyDeck.h"
#include "Card.h"
#include "Exceptions.h"


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


TEST(TestRummyDeck, flip_discard) {
  RummyDeck rd;
  rd.create();

  while (rd.size() != 0) {
    rd.discardDeckTop();
  }

  Card *c = rd.topDiscard();
  EXPECT_EQ(Card::Rank::KING, c->rank);
  EXPECT_EQ(Card::Suit::HEART, c->suit);

  rd.flipDiscard();

  Card *c2 = rd.getCard();
  EXPECT_EQ(Card::Rank::ACE, c2->rank);
  EXPECT_EQ(Card::Suit::CLUB, c2->suit);

  delete c2;
}


TEST(TestRummyDeck, flip_discard_deck_not_empty) {
  RummyDeck rd;
  rd.create();

  EXPECT_THROW(rd.flipDiscard(), unmet_precondition_error);
}
