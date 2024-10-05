#pragma once
#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include <iostream>
using namespace std;

Pokemon::Pokemon() {
    name = "Unknown";
    type = PokemonType::NORMAL;
    health = 50;
    maxHealth = 50;
    attackPower = 10;
}

Pokemon::Pokemon(string p_name, PokemonType p_type, int p_health, int p_attackPower) {
    name = p_name;
    type = p_type;
    maxHealth = p_health;
    health = p_health;
    attackPower = p_attackPower;
}

Pokemon::Pokemon(const Pokemon& other) {
    name = other.name;
    type = other.type;
    health = other.health;
    maxHealth = other.maxHealth;
    attackPower = other.attackPower;
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

void Pokemon::attack(Pokemon& target) {
    cout << name << " attacks " << target.name << " for " << attackPower << " damage!" << endl;
    target.takeDamage(attackPower);
}