#include "game.h"

#include <memory>

using namespace std;

Game::Game() {
    player1 = new Player("Player 1", SymbolX);
    player2 = new Player("Player 2", SymbolO);
    turn = player1;
    boxes = vector<shared_ptr<Box>>(9);
    for (auto i = 0; i < boxes.size(); i++) {
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

Player* Game::move(unsigned int boxNumber) {
    if (boxNumber > 8)
        return nullptr;

    auto box = boxes[boxNumber];

    if (!box->player()) {
        box->setPlayer(turn);

        if (*turn == *player1) {
            turn = player2;
        } else {
            turn = player1;
        }
    }

    return winner();
}

vector<string> Game::currentState() {
    vector<string> state;
    for (auto i = 0; i < boxes.size(); i++) {
        Player* p = boxes[i]->player();
        state.push_back(p ? p->symbolStr() : string(1, SymbolNone));
    }
    return state;
}

string Game::currentBoxState(int boxNumber) {
    Player* p = boxes[boxNumber]->player();
    return p ? p->symbolStr() : string(1, SymbolNone);
}

Player* Game::winner() {
    // Rows
    if (boxesEqual(0, 1, 2))
        return boxes[0]->player();

    if (boxesEqual(3, 4, 5))
        return boxes[3]->player();

    if (boxesEqual(6, 7, 8))
        return boxes[6]->player();

    // Columns
    if (boxesEqual(0, 3, 6))
        return boxes[0]->player();

    if (boxesEqual(1, 4, 7))
        return boxes[1]->player();

    if (boxesEqual(2, 5, 8))
        return boxes[2]->player();

    // Diagonals
    if (boxesEqual(0, 4, 8))
        return boxes[0]->player();

    if (boxesEqual(2, 4, 6))
        return boxes[2]->player();

    return nullptr;
}

bool equals(Player* p1, Player* p2, Player* p3) {
    if (p1 == nullptr || p2 == nullptr || p3 == nullptr)
        return false;
    return (*p1 == *p2) && (*p2 == *p3);
}

bool Game::boxesEqual(int i1, int i2, int i3) {
    return equals(boxes[i1]->player(), boxes[i2]->player(), boxes[i3]->player());
}
