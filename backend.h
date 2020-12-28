#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <vector>

#include "boxcontroller.h"

class Backend : public QObject
{
    Q_OBJECT

private:
    char _turn;
    std::vector<BoxController*> _boxes{9};

public:
    Backend(QObject *parent = nullptr);
    ~Backend();

    std::vector<BoxController*> boxes();

    Q_SLOT void move(int box);
};

#endif
