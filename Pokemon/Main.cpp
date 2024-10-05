#include "include/Main/Game.hpp"
#include "include/Character/Player/Player.hpp"
#include "include/Pokemon/PokemonChoice.hpp"
#include "include/Pokemon/PokemonType.hpp"
#include "include/Character/ProfessorOak.hpp"
#include "include/Utility/Utility.hpp"
#include <iostream>
#include <limits>
#include <string>

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