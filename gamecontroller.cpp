#include "gamecontroller.h"

#include <iostream>

#include "lib/game.h"
#include "lib/player.h"

GameController::GameController(QObject *parent) : QObject(parent)
{
    for (int i = 0; i < 9; i++) {
        _boxes[i] = std::shared_ptr<BoxController>(new BoxController());
    }
}

std::vector<std::shared_ptr<BoxController>> GameController::boxes() {
    return _boxes;
}

void GameController::move(int boxNumber) {
    Game* game = Game::instance();
    Player* winner = game->move(boxNumber);
    std::cout << winner << std::endl;
    std::vector<std::string> state = game->currentState();

    _boxes[boxNumber]->setValue(state[boxNumber].at(0));
}
