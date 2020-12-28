#ifndef SYMBOL_H
#define SYMBOL_H

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
};

#endif