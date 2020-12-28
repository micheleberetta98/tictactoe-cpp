#include "box.h"

Box::Box() {
    p = nullptr;
}

Box::~Box() {}

Player* Box::player() {
    return p;
}

void Box::setPlayer(Player* player) {
    p = player;
}
