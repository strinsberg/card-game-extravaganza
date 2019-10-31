#ifndef MOCKOLDMAIDDECK_H_INCLUDED
#define MOCKOLDMAIDDECK_H_INCLUDED

#include "gmock/gmock.h"
#include "OldMaidDeck.h"
#include "Card.h"

class MockOMDeck : public OldMaidDeck {
 public:
    MockOMDeck() {}
    virtual ~MockOMDeck() {}

    MOCK_METHOD0(getCard, Card*());
    MOCK_METHOD0(size, unsigned int());
    MOCK_METHOD0(shuffle, void());
};

#endif // MOCKDECK_H_INCLUDED
