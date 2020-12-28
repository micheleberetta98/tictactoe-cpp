#include "backend.h"

#include <iostream>
#include "boxcontroller.h"

Backend::Backend(QObject *parent) : QObject(parent) {
    _turn = 'X';

    for (int i = 0; i < 9; i++) {
        _boxes[i] = new BoxController();
    }
}

Backend::~Backend() {
    /* for (int i = 0; i < 9; i++) {
        delete _boxes[i];
    } */
}

std::vector<BoxController*> Backend::boxes() {
    return _boxes;
}

void Backend::move(int box) {
    std::cout << "Box number: " << box << std::endl;
    _boxes[box]->setValue(_turn);
    _turn = _turn == 'X' ? 'O' : 'X';
}
