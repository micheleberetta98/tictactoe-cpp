#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <vector>

#include "box.h"

class Backend : public QObject
{
    Q_OBJECT

private:
    char _turn;
    std::vector<Box*> _boxes{9};

public:
    Backend(QObject *parent = nullptr);
    ~Backend();

    std::vector<Box*> boxes();

    Q_SLOT void move(int box);
};

#endif // BACKEND_H
