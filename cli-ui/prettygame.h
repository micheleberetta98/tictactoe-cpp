#ifndef PRETTY_GAME_H
#define PRETTY_GAME_H

#include "../lib/game.h"

class PrettyGame {
   public:
    PrettyGame();
    ~PrettyGame();

    void move();
    void printGame();
    bool checkForWinner();
    bool playAgain();
};

#endif