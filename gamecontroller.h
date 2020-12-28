#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <memory>
#include <vector>

#include "boxcontroller.h"

class GameController : public QObject
{
    Q_OBJECT
private:
    std::vector<std::shared_ptr<BoxController>> _boxes{9};

public:
    explicit GameController(QObject *parent = nullptr);

    std::vector<std::shared_ptr<BoxController>> boxes();

    Q_SLOT void move(int boxNumber);

};

#endif // GAMECONTROLLER_H
