#include <iostream>

#include "cli-ui/prettygame.h"

using namespace std;

int main() {
    PrettyGame game;
    while (true) {
        game.move();
        game.printGame();
        bool gameFinished = game.checkForWinner();
        if (gameFinished && !game.playAgain()) {
            break;
        }
    }

    return 0;
}