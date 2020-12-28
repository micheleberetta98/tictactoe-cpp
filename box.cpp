#include "box.h"

#include <iostream>

Box::Box(QObject *parent) : QObject(parent) {}

void Box::setId(int id) {
    this->id = id;
    this->value = ' ';
}

void Box::setValue(char value) {
    std::cout << "Changing box value from " << this->value << " to " << value << std::endl;
    this->value = value;
    Q_EMIT textChanged(QString(value));
}
