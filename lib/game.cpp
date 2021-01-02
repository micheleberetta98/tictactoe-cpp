#include "game.h"

#include <memory>

using namespace std;

// Inizializza i giocatori, il turno e le varie celle
Game::Game() {
    player1 = new Player("Giocatore 1 - X", SymbolX);
    player2 = new Player("Giocatore 2 - O", SymbolO);
    turn = player1;
    for (unsigned long i = 0; i < 9; i++) {
        boxes.push_back(shared_ptr<Box>(new Box()));
    }
}

Game::~Game() {
    delete player1;
    delete player2;
    initialized = false;
}

bool Game::initialized = false;
Game* Game::game = nullptr;

// Metodo statico per l'accesso alla singola istanza
Game* Game::instance() {
    if (!initialized) {
        game = new Game();
        initialized = true;
    }
    return game;
}

// Resetta il gioco, fancendone iniziare uno nuovo
// alla prossima chiamata di "instance()"
void Game::newGame() {
    if (game != nullptr)
        game->~Game();
    initialized = false;
}

Player* Game::currentPlayer() {
    return turn;
}

// Esegue una mossa (se possibile)
// e cambia il turno del giocatore
void Game::move(unsigned int boxNumber) {
    if (boxNumber > 8)
        return;

    auto box = boxes[boxNumber];

    if (!box->player()) {
        box->setPlayer(turn);

        if (*turn == *player1) {
            turn = player2;
        } else {
            turn = player1;
        }
    }
}

// Ritorna lo stato delle celle
vector<Box*> Game::currentState() {
    vector<Box*> state;
    for (auto box = boxes.begin(); box != boxes.end(); box++) {
        state.push_back((*box).get());
    }
    return state;
}

// Ritorna lo stato di una cella particolare
Box* Game::currentBoxState(int boxNumber) {
    return boxes[boxNumber].get();
}

// Indica se la board è stata completamente occupata
// Utile per controllare se la partita è terminata con una patta
bool Game::isBoardFull() {
    unsigned long takenBoxes = 0;
    for (auto box = boxes.begin(); box != boxes.end(); box++)
        takenBoxes += (*box)->player() ? 1 : 0;
    return takenBoxes == boxes.size();
}

// Controlla la presenza o meno di un tris in tutta la board
Tris Game::getTris() {
    Tris tris;

    tris = getTrisIn(0, 1, 2);
    if (tris.i1 != -1) return tris;

    tris = getTrisIn(3, 4, 5);
    if (tris.i1 != -1) return tris;

    // Rows
    tris = getTrisIn(6, 7, 8);
    if (tris.i1 != -1) return tris;

    // Columns
    tris = getTrisIn(0, 3, 6);
    if (tris.i1 != -1) return tris;

    tris = getTrisIn(1, 4, 7);
    if (tris.i1 != -1) return tris;

    tris = getTrisIn(2, 5, 8);
    if (tris.i1 != -1) return tris;

    // Diagonals
    tris = getTrisIn(0, 4, 8);
    if (tris.i1 != -1) return tris;

    tris = getTrisIn(2, 4, 6);
    return tris;
}

// Se passato un tris esistente, ritorna il giocatore che
// l'ha fatto
Player* Game::winnerForTris(Tris tris) {
    if (tris.i1 != -1)
        return boxes[tris.i1]->player();

    return nullptr;
}

// Utilità per controllare se 3 player sono uguali
bool equals(Player* p1, Player* p2, Player* p3) {
    if (p1 == nullptr || p2 == nullptr || p3 == nullptr)
        return false;
    return (*p1 == *p2) && (*p2 == *p3);
}

// Funzione di utilità per trovare un tris in 3 posizioni
Tris Game::getTrisIn(int i1, int i2, int i3) {
    Tris tris;

    if (equals(boxes[i1]->player(), boxes[i2]->player(), boxes[i3]->player())) {
        tris.i1 = i1;
        tris.i2 = i2;
        tris.i3 = i3;
    } else {
        tris.i1 = tris.i2 = tris.i3 = -1;
    }

    return tris;
}
