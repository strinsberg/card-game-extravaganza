#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Rummy.h"
#include "Card.h"
#include "Player.h"
#include "MockUI.h"
#include "MockRummyDeck.h"

TEST(RummyTests, countPoints) {
  MockUI* mUI = new MockUI();
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

}

TEST(RummyTests, isOver) {

}

TEST(RummyTests, dealCards) {

}
