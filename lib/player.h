#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "entity.h"
#include "symbol.h"

using namespace std;

// Gestisce un giocatore, che è sia un'entità con un suo nome
// sia un simbolo
class Player : public Entity, public Symbol {
   public:
    Player(string, SymbolEnum);
    virtual ~Player();
    virtual bool operator==(const Player&);

    virtual string toPrettyString();
};

#endif