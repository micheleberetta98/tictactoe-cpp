#include "gamecontroller.h"

#include <string>

#include "lib/game.h"
#include "lib/player.h"

using namespace std;

GameController::GameController(QObject* parent) : QObject(parent) {
    _playerController = shared_ptr<PlayerController>{new PlayerController()};
    _winnerController = shared_ptr<WinnerController>{new WinnerController()};

    for (int i = 0; i < 9; i++) {
        _boxes[i] = shared_ptr<BoxController>(new BoxController());
    }
}

vector<BoxController*> GameController::boxControllers() {
    vector<BoxController*> controllers;
    for (unsigned long i = 0; i < _boxes.size(); i++)
        controllers.push_back(_boxes[i].get());
    return controllers;
}

PlayerController* GameController::playerController() {
    return _playerController.get();
}

WinnerController* GameController::winnerController() {
    return _winnerController.get();
}

void GameController::newGame() {
    Game::newGame();
    _winnerController->updateWinner("");
    updateCurrentPlayerName();
    for (unsigned long i = 0; i < _boxes.size(); i++) {
        updateBoxValue(i);
        updateBoxBackground(i, "lightgray");
    }

    Q_EMIT gameStatusChanged(true);
}

void GameController::move(int boxNumber) {
    Game* game = Game::instance();

    game->move(boxNumber);
    updateBoxValue(boxNumber);

    Tris tris = game->getTris();
    Player* winner = game->winnerForTris(tris);

    updateBoxValue(boxNumber);
    if (winner) {
        updateForWinner(tris, winner);
    } else if (game->isBoardFull()) {
        updateForTie();
    } else {
        updateCurrentPlayerName();
    }
}

void GameController::updateForWinner(Tris tris, Player* winner) {
    _winnerController->updateWinner(winner->getName());
    _playerController->updatePlayerName("");
    updateAllBoxesBackground("darkgray");
    updateBoxBackground(tris.i1, "green");
    updateBoxBackground(tris.i2, "green");
    updateBoxBackground(tris.i3, "green");
    Q_EMIT gameStatusChanged(false);
}

void GameController::updateForTie() {
    _winnerController->updateWinner("Parità");
    _playerController->updatePlayerName("");
    updateAllBoxesBackground("darkgray");
    Q_EMIT gameStatusChanged(false);
}

void GameController::updateBoxValue(int boxNumber) {
    Game* game = Game::instance();
    string boxValue = game->currentBoxState(boxNumber);
    _boxes[boxNumber]->updateValue(boxValue);
}

void GameController::updateAllBoxesBackground(string boxColor) {
    for (unsigned long i = 0; i < _boxes.size(); i++)
        updateBoxBackground(i, boxColor);
}

void GameController::updateBoxBackground(int boxNumber, string boxColor) {
    _boxes[boxNumber]->updateBackground(boxColor);
}

void GameController::updateCurrentPlayerName() {
    Game* game = Game::instance();
    Player* currentPlayer = game->currentPlayer();
    _playerController->updatePlayerName(currentPlayer->getName());
}
