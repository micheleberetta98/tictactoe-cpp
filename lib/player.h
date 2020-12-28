#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "entity.h"
#include "symbol.h"

using namespace std;

class Player : public Entity, public Symbol {
   public:
    Player(string, SymbolEnum);
    virtual ~Player();
    virtual bool operator==(const Player&);
};

#endif