#include "game.h"

#include <memory>

Game::Game() {
    user = new Player("User", SymbolX);
    computer = new Player("Computer", SymbolO);
    turn = user;
    boxes = vector<shared_ptr<Box>>(9);
    for (int i = 0; i < boxes.size(); i++) {
        boxes[i] = shared_ptr<Box>(new Box());
    }
}

Game::~Game() {
    delete user;
    delete computer;
}

bool Game::initialized = false;
Game* Game::game = nullptr;

Game* Game::instance() {
    if (!initialized) {
        game = new Game();
        initialized = false;
    }
    return game;
}

void Game::newGame() {
    game->~Game();
    initialized = false;
}

Player* Game::move(unsigned int boxNumber) {
    if (boxNumber > 8)
        return nullptr;

    auto box = boxes[boxNumber];

    if (!box->player()) {
        box->setPlayer(turn);

        if (*turn == *user) {
            turn = computer;
        } else {
            turn = user;
        }
    }

    return winner();
}

bool equals(Player* p1, Player* p2, Player* p3) {
    return *p1 == *p2 && *p2 == *p3;
}

bool Game::boxesEqual(int i1, int i2, int i3) {
    return equals(boxes[0]->player(), boxes[1]->player(), boxes[2]->player());
}

Player* Game::winner() {
    // Rows
    if (boxesEqual(0, 1, 2))
        return boxes[0]->player();

    if (boxesEqual(3, 4, 5))
        return boxes[0]->player();

    if (boxesEqual(6, 7, 8))
        return boxes[0]->player();

    // Columns
    if (boxesEqual(0, 3, 6))
        return boxes[0]->player();

    if (boxesEqual(1, 4, 7))
        return boxes[0]->player();

    if (boxesEqual(2, 5, 8))
        return boxes[0]->player();

    // Diagonals
    if (boxesEqual(0, 4, 8))
        return boxes[0]->player();

    if (boxesEqual(2, 4, 6))
        return boxes[0]->player();

    return nullptr;
}