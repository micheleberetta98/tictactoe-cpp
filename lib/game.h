#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

#include "box.h"
#include "player.h"

using namespace std;

class Game {
   private:
    static bool initialized;
    static Game* game;

    Player* player1;
    Player* player2;
    Player* turn;
    vector<shared_ptr<Box>> boxes;

    Game();
    bool boxesEqual(int, int, int);
    Player* winner();

   public:
    ~Game();

    static Game* instance();
    static void newGame();
    Player* move(unsigned int);
    Player* currentPlayer();
};

#endif