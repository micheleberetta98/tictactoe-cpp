#ifndef BOX_H
#define BOX_H

#include <memory>

#include "player.h"

using namespace std;

class Box {
   private:
    Player* p;

   public:
    Box();
    ~Box();

    Player* player();
    void setPlayer(Player*);
};

#endif