#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

#include "box.h"
#include "player.h"

using namespace std;

struct Tris {
    int i1 = -1;
    int i2 = -1;
    int i3 = -1;
};
class Game {
   private:
    static bool initialized;
    static Game* game;

    Player* player1;
    Player* player2;
    Player* turn;
    vector<shared_ptr<Box>> boxes;

    Game();
    Tris getTrisIn(int, int, int);

   public:
    ~Game();

    static Game* instance();
    static void newGame();

    void move(unsigned int);
    Player* currentPlayer();
    vector<string> currentState();
    string currentBoxState(int);
    bool isBoardFull();
    Player* winnerForTris(Tris);
    Tris getTris();
};

#endif
