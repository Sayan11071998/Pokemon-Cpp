#include "Pokemon.hpp"
#include "PokemonType.hpp"
#include <iostream>
using namespace std;

Pokemon::Pokemon() {
    name = "Unknown";
    type = PokemonType::NORMAL;
    health = 50;
}

Pokemon::Pokemon(string p_name, PokemonType p_type, int p_health) {
    name = p_name;
    type = p_type;
    health = p_health;
}

Pokemon::Pokemon(const Pokemon& other) {
    name = other.name;
    type = other.type;
    health = other.health;
}

Pokemon::~Pokemon() {
    // Destructor logic (if any) goes here
}

void Pokemon::attack(Pokemon& target) {
    int damage = attackPower;
    cout << name << " attacks " << target.name << " for " << damage << " damage!" << endl;
    target.takeDamage(damage);
}

void Pokemon::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

bool Pokemon::isFainted() const {
    return health <= 0;
}

void Pokemon::heal() {
    health = maxHealth;
}