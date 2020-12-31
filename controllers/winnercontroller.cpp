#include "winnercontroller.h"

#include <string>

WinnerController::WinnerController(QObject *parent) : QObject(parent) {}

void WinnerController::updateWinner(std::string winnerName) {
    Q_EMIT textChanged(QString(winnerName.c_str()));
}
