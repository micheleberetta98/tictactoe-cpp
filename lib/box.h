#ifndef BOX_H
#define BOX_H

#include <memory>
#include <string>

#include "player.h"

class Box {
   private:
    Player* p;

   public:
    Box();
    ~Box();

    Player* player();
    void setPlayer(Player*);

    std::string innerSymbol();
};

#endif