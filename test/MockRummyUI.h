#ifndef MOCK_RUMMYUI_H_INCLUDED
#define MOCK_RUMMYUI_H_INCLUDED

#include "RummyUI.h"
#include <list>

class MockRummyUI : public RummyUI {
 public:
    MockRummyUI() {}
    virtual ~MockRummyUI() {}
    MOCK_METHOD1(takeTurn, void(Player*));
    MOCK_METHOD1(displayTable, void(RummyTable*));
    MOCK_METHOD1(displayHand, void(std::list<Card*>*));
    MOCK_METHOD1(drawFromDeck, int(RummyDeck*));
    MOCK_METHOD1(playMeld, std::vector<int>(std::list<Card*>*));
    MOCK_METHOD1(layOff, int(std::list<Card*>*));

    MOCK_METHOD2(requestCard, unsigned int(Player*, std::list<Card*>*));
    MOCK_METHOD0(playFailed, void());
    MOCK_METHOD0(playSucceeded, void());
    MOCK_METHOD1(outOfGame, void(Player*));
    MOCK_METHOD2(choosePlayer, unsigned int(unsigned int, unsigned int));
};


#endif // MOCKUI_H_INCLUDED
