#include "symbol.h"

Symbol::Symbol(SymbolEnum s) : s(s){};

Symbol::~Symbol(){};

SymbolEnum Symbol::symbolValue() {
    return s;
}

std::string Symbol::symbolStr() {
    return std::string(1, s);
}