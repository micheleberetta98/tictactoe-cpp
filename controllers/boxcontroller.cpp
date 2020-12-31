#include "boxcontroller.h"

#include <string>

BoxController::BoxController(QObject *parent) : QObject(parent) {}

void BoxController::updateValue(std::string value) {
    Q_EMIT textChanged(QString(value.c_str()));
}

void BoxController::updateBackground(std::string backgroundColor) {
    Q_EMIT backgroundChanged(QString(backgroundColor.c_str()));
}
