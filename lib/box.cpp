#include "box.h"

#include <string>

#include "symbol.h"

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

std::string Box::innerSymbol() {
    if (p) return p->symbolStr();
    return Symbol(SymbolNone).symbolStr();
}