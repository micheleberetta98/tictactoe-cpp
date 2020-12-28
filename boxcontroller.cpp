#include "boxcontroller.h"

#include <string>

BoxController::BoxController(QObject *parent) : QObject(parent) {}

void BoxController::setId(int id) {
    this->id = id;
    this->value = ' ';
}

void BoxController::setValue(std::string value) {
    this->value = value;
    Q_EMIT textChanged(QString(value.c_str()));
}
