#include "boxcontroller.h"

#include <iostream>

BoxController::BoxController(QObject *parent) : QObject(parent) {}

void BoxController::setId(int id) {
    this->id = id;
    this->value = ' ';
}

void BoxController::setValue(char value) {
    std::cout << "Changing box value from " << this->value << " to " << value << std::endl;
    this->value = value;
    Q_EMIT textChanged(QString(value));
}
