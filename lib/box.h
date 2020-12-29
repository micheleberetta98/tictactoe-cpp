#ifndef BOX_H
#define BOX_H

#include <memory>
#include <string>

#include "player.h"
#include "pretty.h"

using namespace std;

class Box : public Pretty {
   private:
    Player* p;

   public:
    Box();
    ~Box();

    Player* player();
    void setPlayer(Player*);

    string toPrettyString();
};

#endif