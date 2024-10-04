#include "Player.hpp"
#include "PokemonChoice.hpp"
#include "PokemonType.hpp"
#include "Utility.hpp"
#include <iostream>
#include <limits> // Include this header to use std::numeric_limits
#include <string>
using namespace std;

// Professor Oak class
class ProfessorOak {
public:
    // Data Members
    string name;

    // Parameterized Constructors
    ProfessorOak(string p_name) {
        name = p_name;
    }

    // Method to greet the player
    void greetPlayer(Player& player) {
        cout << name << ": Hello there! Welcome to the world of Pokemon!" << endl;
        Utility::WaitforEnter();
        cout << name << ": My name is Oak. People call me the Pokemon Professor!" << endl;
        Utility::WaitforEnter();
        cout << name << ": But enough about me. Let's talk about you!" << endl;
        Utility::WaitforEnter();
    }

    // Method to ask the player to choose a Pokemon
    void offerPokemonChoices(Player& player) {
        cout << name << ": First, tell me, what’s your name?" << endl;
        getline(cin, player.name);
        cout << name << ": Ah, " << player.name << "! What a fantastic name!" << endl;
        Utility::WaitforEnter();
        cout << name << ": You must be eager to start your adventure. But first, you’ll need a Pokemon of your own!" << endl;
        Utility::WaitforEnter();

        // Presenting Pokemon choices 
        cout << name << ": I have three Pokemon here with me. They’re all quite feisty!" << endl;
        Utility::WaitforEnter();
        cout << name << ": Choose wisely...\n"; cout << "1. Charmander - The fire type. A real hothead!" << endl;
        cout << "2. Bulbasaur - The grass type. Calm and collected!" << endl;
        cout << "3. Squirtle - The water type. Cool as a cucumber!" << endl;

        int choice;
        cout << name << ": So, which one will it be? Enter the number of your choice: ";
        cin >> choice;

        player.choosePokemon(choice);
        Utility::WaitforEnter();
    }

    // New method for the main quest conversation
    void explainMainQuest(Player& player) {
        Utility::clearConsole();

        cout << "Professor Oak: Ah, " << player.name << ", let me tell you about your grand adventure that's about to unfold!" << endl;
        Utility::WaitforEnter();
        cout << "Professor Oak: You see, becoming a Pokémon Master is no easy feat. It takes courage, wisdom, and a bit of luck." << endl;
        Utility::WaitforEnter();
        cout << "Professor Oak: Your main mission is to collect all the Pokémon Badges and defeat the Pokémon League. Only then can you challenge the Elite Four and aim for the title of Champion." << endl;
        Utility::WaitforEnter();
        cout << player.name << ": Wait, isn’t that just like every other Pokémon game?" << endl;
        Utility::WaitforEnter();
        cout << "Professor Oak: No breaking the fourth wall, " << player.name << "! This is serious business." << endl;
        Utility::WaitforEnter();
        cout << "Professor Oak: To achieve this, you must capture new Pokémon, battle wild creatures, challenge gym leaders, and keep your Pokémon healthy at the PokeCenter." << endl;
        Utility::WaitforEnter();
        cout << "Professor Oak: Remember, you can only carry a limited number of Pokémon. Choose wisely who you want on your team!" << endl;
        Utility::WaitforEnter();
        cout << player.name << ": Piece of cake, right?" << endl;
        Utility::WaitforEnter();
        cout << "Professor Oak: Ha! That’s what everyone thinks. But the path to becoming a Champion is filled with obstacles. Lose a battle, and it’s back to the start!." << endl;
        Utility::WaitforEnter();
        cout << "Professor Oak: So, what do you say? Are you ready to embark on this epic journey to become the next Pokémon Champion?" << endl;
        Utility::WaitforEnter();
        cout << player.name << ": Ready as I’ll ever be, Professor!" << endl;
        Utility::WaitforEnter();
        cout << "Professor Oak: That’s the spirit! Now, your journey begins. Remember, it’s not just about battling—it’s about forming bonds with your Pokémon. Go, Trainer, the world of Pokémon awaits you!" << endl;
        Utility::WaitforEnter();
        cout << "Professor Oak: Oh, and about the actual game loop… let’s just pretend I didn’t forget to set it up. Onwards!" << endl;
        Utility::WaitforEnter();
    }
};

// Function to handle the main game loop
void gameLoop(Player &player) {
    int choice;
    bool keepPlaying = true;

    while (keepPlaying) {
        Utility::clearConsole();

        // Display options to the player
        cout << "\nWhat would you like to do next, " << player.name << "?" << endl;
        cout << "1. Battle Wild Pokémon" << endl;
        cout << "2. Visit PokeCenter" << endl;
        cout << "3. Challenge Gyms" << endl;
        cout << "4. Enter Pokémon League" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        Utility::clearInputBuffer();

        // Clear the newline character left in the buffer after cin >> choice
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Process the player's choice and display the corresponding message
        switch (choice) {
        case 1:
            cout << "You look around... but all the wild Pokémon are on vacation. Maybe try again later?" << endl;
            break;
        case 2:
            cout << "You head to the PokeCenter, but Nurse Joy is out on a coffee break. Guess your Pokémon will have to tough it out for now!" << endl;
            break;
        case 3:
            cout << "You march up to the Gym, but it's closed for renovations. Seems like even Gym Leaders need a break!" << endl;
            break;
        case 4:
            cout << "You boldly step towards the Pokémon League... but the gatekeeper laughs and says, 'Maybe next time, champ!" << endl;
            break;
        case 5:
            cout << "You try to quit, but Professor Oak's voice echoes: 'There's no quitting in Pokémon training!'" << endl;
            cout << "Are you sure you want to quit? (y/n): ";

            char quitChoice;
            cin >> quitChoice;
            if (quitChoice == 'y' || quitChoice == 'Y') {
                keepPlaying = false;
            }

            break;
        default:
            cout << "That's not a valid choice. Try again!" << endl;
        }
        
        Utility::WaitforEnter();
    }

    cout << "Goodbye, " << player.name << "! Thanks for playing!" << endl;
}

int main() {

    // Create Pokemon and Player objects for the game
    Pokemon charmander("Charmander", PokemonType::FIRE, 100); // Using parameterized constructor

    // Continue with the main flow of the game
    ProfessorOak professor("Professor Oak");
    Player player("Ash", charmander);

    // Greet the player and offer Pokemon choices
    professor.greetPlayer(player);
    professor.offerPokemonChoices(player);

    // Explain the main quest
    professor.explainMainQuest(player);

    // Start the main game loop
    gameLoop(player);


    return 0;

}