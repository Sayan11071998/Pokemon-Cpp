#include "include/Main/Game.hpp"
#include "include/Character/Player/Player.hpp"
#include "include/Character/ProfessorOak.hpp"
#include <iostream>
#include <limits> // Include this header to use std::numeric_limits

class IStatusEffect {
public:
    // Apply the effect (e.g., poison, burn)
    virtual void applyEffect(Pokemon* target) = 0;

    // Get the name of the effect
    virtual std::string getEffectName() = 0;

    // Apply the changes due to effect after the end of each turn
    // Returns true if the Pokémon can move, else false
    virtual bool turnEndEffect(Pokemon* target) = 0;

    // Remove the effect
    virtual void clearEffect(Pokemon* target) = 0;

    virtual ~IStatusEffect() = default;
}

using namespace N_Character;
using namespace N_Player;

int main() {

    // Continue with the main flow of the game
    ProfessorOak* professor = new ProfessorOak("Professor Oak");
    N_Player::Player* player = new N_Player::Player();

    // Greet the player and offer Pokemon choices
    professor->greetPlayer(player);
    professor->offerPokemonChoices(player);

    // Explain the main quest
    professor->explainMainQuest(player);

    // Start the main game loop
    N_Main::Game* game = new N_Main::Game();
    game->gameLoop(player);

    delete(professor);
    delete(player);
    delete(game);

    return 0;
}