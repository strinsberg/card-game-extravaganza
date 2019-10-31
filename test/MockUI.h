#ifndef MOCKUI_H_INCLUDED
#define MOCKUI_H_INCLUDED

#include "GameUI.h"
#include <list>

class MockUI : public GameUI {
 public:
    MockUI() {}
    virtual ~MockUI() {}
    MOCK_METHOD2(requestCard, unsigned int(Player*, std::list<Card*>*));
    MOCK_METHOD0(playFailed, void());
    MOCK_METHOD0(playSucceeded, void());
    MOCK_METHOD1(outOfGame, void(Player*));
    MOCK_METHOD2(choosePlayer, unsigned int(unsigned int, unsigned int));
};


#endif // MOCKUI_H_INCLUDED
