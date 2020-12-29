#include "symbol.h"

#include <string>

using namespace std;

Symbol::Symbol(SymbolEnum s) : s(s){};

Symbol::~Symbol(){};

SymbolEnum Symbol::symbolValue() {
    return s;
}

string Symbol::symbolStr() {
    return string(1, s);
}

string Symbol::toPrettyString() {
    return symbolStr();
}