#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

#include "box.h"
#include "player.h"

using namespace std;

// Struttura che rappresenta un tris
// (o l'assenza di uno se i1 = -1)
struct Tris {
    int i1 = -1;
    int i2 = -1;
    int i3 = -1;
};

// La classe Game implementa il pattern singleton e
// gestisce il gioco nella sua interezza.
// Fornisce dei metodi per poter accedere alle varie
// informazioni mantenute nello stato privato.
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
    vector<Box*> currentState();
    Box* currentBoxState(int);
    bool isBoardFull();
    Player* winnerForTris(Tris);
    Tris getTris();
};

#endif
