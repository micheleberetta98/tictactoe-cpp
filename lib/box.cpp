#include "box.h"

#include <string>

#include "symbol.h"

using namespace std;

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

string Box::toPrettyString() {
    if (p) return p->symbolStr();
    return Symbol(SymbolNone).symbolStr();
}