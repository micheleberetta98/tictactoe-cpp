#include "entity.h"

#include <string>

using namespace std;

Entity::Entity(string name) : name(name) {}

Entity::~Entity() {}

string Entity::getName() {
    return name;
}

string Entity::toPrettyString() {
    return getName();
}