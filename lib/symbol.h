#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

#include "pretty.h"

using namespace std;

enum SymbolEnum : char {
    SymbolX = 'X',
    SymbolO = 'O',
    SymbolNone = ' ',
};

// Classe che gestisce un simbolo grafico
class Symbol : virtual public Pretty {
   protected:
    SymbolEnum s;

   public:
    Symbol(SymbolEnum);
    virtual ~Symbol();

    SymbolEnum symbolValue();
    string symbolStr();

    string toPrettyString();
};

#endif