#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include "pretty.h"

using namespace std;

// Gestisce una entità con un suo nome
class Entity : virtual public Pretty {
   protected:
    string name;

   public:
    Entity(string);
    virtual ~Entity();

    string getName();

    string toPrettyString();
};

#endif