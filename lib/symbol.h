#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

enum SymbolEnum : char {
    SymbolX = 'X',
    SymbolO = 'O',
    SymbolNone = ' ',
};

class Symbol {
   protected:
    SymbolEnum s;

   public:
    Symbol(SymbolEnum);
    virtual ~Symbol();

    SymbolEnum symbolValue();
    std::string symbolStr();
};

#endif