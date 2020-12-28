#include "player.h"

Player::Player(string name, SymbolEnum symbol) : Entity(name), Symbol(symbol) {}
Player::~Player() {}

bool Player::operator==(const Player& other) {
    return this->name == other.name && this->s == other.s;
}