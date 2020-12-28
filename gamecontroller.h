#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <memory>
#include <string>
#include <vector>

#include "boxcontroller.h"
#include "lib/game.h"
#include "lib/player.h"
#include "playercontroller.h"
#include "winnercontroller.h"

using namespace std;

class GameController : public QObject {
    Q_OBJECT
   private:
    vector<shared_ptr<BoxController>> _boxes{9};
    shared_ptr<PlayerController> _playerController;
    shared_ptr<WinnerController> _winnerController;

    void updateForWinner(Tris tris, Player* winner);
    void updateForTie();

    void updateBoxValue(int boxNumber);
    void updateAllBoxesBackground(string boxColor);
    void updateBoxBackground(int boxNumber, string boxColor);
    void updateCurrentPlayerName();

   public:
    explicit GameController(QObject* parent = nullptr);

    vector<BoxController*> boxControllers();
    PlayerController* playerController();
    WinnerController* winnerController();

    Q_SIGNAL void gameStatusChanged(bool started);

    Q_SLOT void newGame();
    Q_SLOT void move(int boxNumber);
};

#endif
