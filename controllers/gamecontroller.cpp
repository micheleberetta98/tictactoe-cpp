#include "gamecontroller.h"

#include <string>

#include "../lib/box.h"
#include "../lib/game.h"
#include "../lib/player.h"

using namespace std;

// L'istanziamento prevede l'istanziamento anche degli altri controller
GameController::GameController(QObject* parent) : QObject(parent) {
    _playerController = shared_ptr<PlayerController>{new PlayerController()};
    _winnerController = shared_ptr<WinnerController>{new WinnerController()};

    for (int i = 0; i < 9; i++) {
        _boxes[i] = shared_ptr<BoxController>(new BoxController());
    }
}

// Getter per accedere ai vari box controller
vector<BoxController*> GameController::boxControllers() {
    vector<BoxController*> controllers;
    for (auto box = _boxes.begin(); box != _boxes.end(); box++)
        controllers.push_back((*box).get());
    return controllers;
}

// Getter per accedere al controller del giocatore
PlayerController* GameController::playerController() {
    return _playerController.get();
}

// Getter per accedere al controller del vincitore
WinnerController* GameController::winnerController() {
    return _winnerController.get();
}

// Reset del gioco: pulisce lo stato precedente e
// riporta la board allo stato iniziale
void GameController::newGame() {
    Game::newGame();
    _winnerController->updateWinner("---");
    updateCurrentPlayerName();
    for (unsigned long i = 0; i < _boxes.size(); i++) {
        updateBoxValue(i);
        updateBoxBackground(i, "lightgray");
    }

    Q_EMIT gameStatusChanged(true);
}

// SLOT usato per eseguire una mossa
// Emette degli eventi per l'aggiornamento dell'interfaccia grafica
// (per le box, il turno ed eventualmente il vincitore)
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

// Funzione di utilità che aggiorna l'interfaccia se si ha un vincitore
void GameController::updateForWinner(Tris tris, Player* winner) {
    _winnerController->updateWinner(winner->toPrettyString());
    _playerController->updatePlayerName("---");
    updateAllBoxesBackground("darkgray");
    updateBoxBackground(tris.i1, "green");
    updateBoxBackground(tris.i2, "green");
    updateBoxBackground(tris.i3, "green");
    Q_EMIT gameStatusChanged(false);
}

// Funzione di utilità che aggiorna l'interfaccia se si ha una patta
void GameController::updateForTie() {
    _winnerController->updateWinner("Parità");
    _playerController->updatePlayerName("---");
    updateAllBoxesBackground("darkgray");
    Q_EMIT gameStatusChanged(false);
}

// Aggiorna il contenuto di una box particolare
void GameController::updateBoxValue(int boxNumber) {
    Game* game = Game::instance();
    Box* box = game->currentBoxState(boxNumber);
    _boxes[boxNumber]->updateValue(box->toPrettyString());
}

// Aggiorna il background di tutte le box
void GameController::updateAllBoxesBackground(string boxColor) {
    for (unsigned long i = 0; i < _boxes.size(); i++)
        updateBoxBackground(i, boxColor);
}

// Aggiorna il background di una box particolare
void GameController::updateBoxBackground(int boxNumber, string boxColor) {
    _boxes[boxNumber]->updateBackground(boxColor);
}

// Aggiorna l'indicazione del turno con il nome del giocatore
void GameController::updateCurrentPlayerName() {
    Game* game = Game::instance();
    Player* currentPlayer = game->currentPlayer();
    _playerController->updatePlayerName(currentPlayer->toPrettyString());
}
