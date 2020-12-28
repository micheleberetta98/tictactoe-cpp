#include "entity.h"

Entity::Entity(string name) : name(name) {}

Entity::~Entity() {}

string Entity::getName() {
    return name;
}