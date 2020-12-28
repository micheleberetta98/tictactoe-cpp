#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <memory>
#include <vector>

#include "boxcontroller.h"
#include "playercontroller.h"

using namespace std;

class GameController : public QObject
{
    Q_OBJECT
private:
    vector<shared_ptr<BoxController>> _boxes{9};
    shared_ptr<PlayerController> _playerController;

    void updateBoxValue(int boxNumber);
    void updateCurrentPlayerName();

public:
    explicit GameController(QObject *parent = nullptr);

    vector<BoxController*> boxControllers();

    PlayerController* playerController();

    Q_SLOT void move(int boxNumber);

};

#endif // GAMECONTROLLER_H
