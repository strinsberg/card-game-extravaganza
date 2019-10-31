#include "OldMaidUI.h"
#include "OldMaid.h"
#include "OldMaidDeck.h"

int main() {
    Deck* d = new OldMaidDeck();
    d->create();
    GameUI* ui = new OldMaidUI();
    Game* g = new OldMaid(ui, d);

    g->addPlayer(new Player("John"));
    g->addPlayer(new Player("Danielle"));
    g->addPlayer(new Player("Tara"));

    g->start();

    delete g;
}
