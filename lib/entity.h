#ifndef ENTITY_H
#define ENTITY_H

#include <string>

using namespace std;

class Entity {
   protected:
    string name;

   public:
    Entity(string);
    virtual ~Entity();

    string getName();
};

#endif