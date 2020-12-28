#include "gamecontroller.h"

#include <string>

#include "lib/game.h"
#include "lib/player.h"

using namespace std;

GameController::GameController(QObject *parent) : QObject(parent)
{
    _playerController = shared_ptr<PlayerController>{new PlayerController()};
    updateCurrentPlayerName();

    for (int i = 0; i < 9; i++) {
        _boxes[i] = shared_ptr<BoxController>(new BoxController());
    }
}

vector<BoxController*> GameController::boxControllers() {
    vector<BoxController*> controllers;
    for (auto i = 0; i < _boxes.size(); i++)
        controllers.push_back(_boxes[i].get());
    return controllers;
}

PlayerController* GameController::playerController() {
    return _playerController.get();
}

void GameController::move(int boxNumber) {
    Game* game = Game::instance();
    Player* winner = game->move(boxNumber);

    updateCurrentPlayerName();
    updateBoxValue(boxNumber);
}

void GameController::updateBoxValue(int boxNumber) {
    Game* game = Game::instance();
    string boxValue = game->currentBoxState(boxNumber);
    _boxes[boxNumber]->setValue(boxValue);
}

void GameController::updateCurrentPlayerName() {
    Game* game = Game::instance();
    Player* currentPlayer = game->currentPlayer();
    _playerController->changePlayerName(currentPlayer->getName());
}
