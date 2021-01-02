#ifndef PRETTY_GAME_H
#define PRETTY_GAME_H

#include "../lib/game.h"

// Questa classe fa da wrapper a game e gestisce il gioco
// tramite interfaccia da riga di comando.
// È il parallelo per CLI di GameController.
class PrettyGame {
   public:
    PrettyGame();
    virtual ~PrettyGame();

    void move();
    void printGame();
    bool checkForWinner();
    bool playAgain();
};

#endif