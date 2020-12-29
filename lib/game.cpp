#include "game.h"

#include <memory>

using namespace std;

Game::Game() {
    player1 = new Player("Giocatore 1 - X", SymbolX);
    player2 = new Player("Giocatore 2 - O", SymbolO);
    turn = player1;
    boxes = vector<shared_ptr<Box>>(9);
    for (unsigned long i = 0; i < boxes.size(); i++) {
        boxes[i] = shared_ptr<Box>(new Box());
    }
}

Game::~Game() {
    delete player1;
    delete player2;
}

bool Game::initialized = false;
Game* Game::game = nullptr;

Game* Game::instance() {
    if (!initialized) {
        game = new Game();
        initialized = true;
    }
    return game;
}

void Game::newGame() {
    if (game != nullptr)
        game->~Game();
    initialized = false;
}

Player* Game::currentPlayer() {
    return turn;
}

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

vector<string> Game::currentState() {
    vector<string> state;
    for (unsigned long i = 0; i < boxes.size(); i++) {
        Player* p = boxes[i]->player();
        state.push_back(p ? p->symbolStr() : string(1, SymbolNone));
    }
    return state;
}

string Game::currentBoxState(int boxNumber) {
    return boxes[boxNumber]->innerSymbol();
}

bool Game::isBoardFull() {
    unsigned long takenBoxes = 0;
    for (unsigned long i = 0; i < boxes.size(); i++)
        takenBoxes += (boxes[i]->player() ? 1 : 0);
    return takenBoxes == boxes.size();
}

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

Player* Game::winnerForTris(Tris tris) {
    if (tris.i1 != -1)
        return boxes[tris.i1]->player();

    return nullptr;
}

bool equals(Player* p1, Player* p2, Player* p3) {
    if (p1 == nullptr || p2 == nullptr || p3 == nullptr)
        return false;
    return (*p1 == *p2) && (*p2 == *p3);
}

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
