#ifndef PRETTY_H
#define PRETTY_H

#include <string>

// Classe astratta che indica i tipi che sono stampabili
// a terminale
class Pretty {
    virtual std::string toPrettyString() = 0;
};

#endif