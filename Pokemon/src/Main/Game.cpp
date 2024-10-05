#pragma once
#include "../../include/Main/Game.hpp"
#include "../../include/Battle/BattleManager.hpp"
#include "../../include/Character/Player/Player.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Utility/Utility.hpp"
#include "../../include/Battle/WildEncounterManager.hpp"
#include <iostream>
using namespace std;

Game::Game() {
    // Create a sample grass environment with actual Pokemon objects
    forestGrass = { "Forest",
                   {Pokemon("Pidgey", PokemonType::NORMAL, 40, 7),
                    Pokemon("Caterpie", PokemonType::BUG, 35, 5),
                    Pokemon("Zubat", PokemonType::POISON, 30, 8)},
                   70 };
}

void Game::gameLoop(Player& player) {

    int choice;
    bool keepPlaying = true;
    BattleManager battleManager;
    WildEncounterManager encounterManager;
    Pokemon wildPokemon;

    while (keepPlaying) {
        Utility::clearConsole();

        // Display options to the player
        cout << "\nWhat would you like to do next, " << player.name << "?" << endl;
        cout << "1. Battle Wild Pok�mon" << endl;
        cout << "2. Visit PokeCenter" << endl;
        cout << "3. Challenge Gyms" << endl;
        cout << "4. Enter Pok�mon League" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        Utility::clearInputBuffer();

        // Process the player's choice and display the corresponding message
        switch (choice) {
        case 1: {
            visitPokeCenter(player);
            break;
        }
        case 2: {
            cout << "You head to the PokeCenter" << endl;
            player.chosenPokemon.heal();
            cout << player.chosenPokemon.name << "'s health is fully restored!" << endl;
            break;
        }
        case 3: {
            cout << "You march up to the Gym, but it's closed for renovations. Seems like even Gym Leaders need a break!" << endl;
            break;
        }
        case 4: {
            cout << "You boldly step towards the Pok�mon League... but the gatekeeper laughs and says, 'Maybe next time, champ!'" << endl;
            break;
        }
        case 5: {
            cout << "You try to quit, but Professor Oak's voice echoes: 'There's no quitting in Pok�mon training!'" << endl;
            cout << "Are you sure you want to quit? (y/n): ";
            char quitChoice;
            cin >> quitChoice;
            if (quitChoice == 'y' || quitChoice == 'Y') {
                keepPlaying = false;
            }
            break;
        }
        default: {
            cout << "That's not a valid choice. Try again!" << endl;
            break;
        }
        }

        Utility::waitforEnter();
    }

    cout << "Goodbye, " << player.name << "! Thanks for playing!" << endl;
}

void Game::visitPokeCenter(Player& player) {
    if (player.chosenPokemon.health == player.chosenPokemon.maxHealth) {
        cout << "Your Pok�mon is already at full health!" << endl;
    }
    else {
        cout << "You head to the PokeCenter." << endl;
        cout << "Healing your Pok�mon..." << endl;
        Utility::waitforEnter();
        player.chosenPokemon.heal();
        cout << player.chosenPokemon.name << "'s health is fully restored!" << endl;
    }
}