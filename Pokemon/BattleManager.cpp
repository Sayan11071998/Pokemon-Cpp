#include "BattleManager.hpp"
#include "Utility.hpp"
#include <iostream>
using namespace std;

void BattleManager::startBattle(Player& player, Pokemon& wildPokemon) {
	cout << "A wild " << wildPokemon.name << " appeared!" << endl;
	battle(player.chosenPokemon, wildPokemon);
}

void BattleManager::battle(Pokemon& playerPokemon, Pokemon& wildPokemon) {
    cout << "A wild " << wildPokemon.name << " appeared!" << endl;

    while (!playerPokemon.isFainted() && !wildPokemon.isFainted()) {
        playerPokemon.attack(wildPokemon);

        if (!wildPokemon.isFainted()) {
            wildPokemon.attack(playerPokemon);
        }
    }

    if (playerPokemon.isFainted()) {
        cout << playerPokemon.name << "has fainted! You lose the battle." << endl;
    }
    else {
        cout << "You defeated the wild " << wildPokemon.name << "!" << endl;
    }
}

void BattleManager::handleBattleOutcome(Player& player, bool playerWon) {
    if (playerWon) {
        cout << player.chosenPokemon.name << " is victorious! Keep an eye on your Pokémon's health." << endl;
    }
    else {
        cout << "Oh no! " << player.chosenPokemon.name << " fainted! You need to visit the PokeCenter." << endl;
        Utility::WaitforEnter();
        cout << "Game Over." << endl;
    }
}