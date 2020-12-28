#include "symbol.h"

Symbol::Symbol(SymbolEnum s) : s(s){};

Symbol::~Symbol(){};

SymbolEnum Symbol::symbolValue() {
    return s;
}