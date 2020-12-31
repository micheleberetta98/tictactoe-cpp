#include "playercontroller.h"

#include <string>

PlayerController::PlayerController(QObject *parent) : QObject(parent) {}

void PlayerController::updatePlayerName(std::string playerName) {
    Q_EMIT textChanged(QString(playerName.c_str()));
}
