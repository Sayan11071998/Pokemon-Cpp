#include "Game.hpp"
#include "Player.hpp"
#include "PokemonChoice.hpp"
#include "PokemonType.hpp"
#include "ProfessorOak.hpp"
#include "Utility.hpp"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

void battle(Pokemon& playerPokemon, Pokemon& wildPokemon) {
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

int main() {

    // Continue with the main flow of the game
    ProfessorOak professor("Professor Oak");
    Player player;

    // Greet the player and offer Pokemon choices
    professor.greetPlayer(player);
    professor.offerPokemonChoices(player);

    // Explain the main quest
    professor.explainMainQuest(player);

    // Start the main game loop
    Game game;
    game.gameLoop(player);


    return 0;

}