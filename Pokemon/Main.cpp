#include<iostream>
#include <limits>
#include<string>
using namespace std;

// Function to clear the console
void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    (void)system("clear");
#endif
}

// Function to wait for user to press Enter
void WaitforEnter() {
    cin.get();
}

// Enum for Pokemon Choices
enum class PokemonChoice {
    CHARMANDER = 1,
    BULBASAUR,
    SQUIRTLE,
    PIKACHU
};

// Enum for Pokemon Types
enum class PokemonType {
    FIRE,
    GRASS,
    WATER,
    ELECTRIC,
    NORMAL
};

// Pokemon class
class Pokemon {
public:
    // Data Members
    string name;
    PokemonType type;
    int health;

    // Defalut Constructors
    Pokemon() {
        name = "Unknown";
        type = PokemonType::NORMAL;
        health = 50;
    }
    // Parameterized Constructors
    Pokemon(string p_name, PokemonType p_type, int p_health) {
        name = p_name;
        type = p_type;
        health = p_health;
    }
    // Copy constructor
    Pokemon(const Pokemon &other) {
        name = other.name;
        type = other.type;
        health = other.health;
    }

    // Destructor
    ~Pokemon() {}

    // Attack Method
    void attack() {
        cout << name << " attacks with a powerful move!" << endl;
    }
};

// Player class
class Player {
public:
    // Data Members
    string name;
    Pokemon chosenPokemon;

    // Defalut Constructors
    Player() {
        name = "Trainer";
        chosenPokemon = Pokemon();
    }
    // Parameterized Constructors
    Player(string p_name, Pokemon p_chosenPokemon) {
        name = p_name;
        chosenPokemon = p_chosenPokemon;
    }

    // Method to choose a Pokemon
    void choosePokemon(int choice) {
        switch ((PokemonChoice)choice) {
        case PokemonChoice::CHARMANDER:
            chosenPokemon = Pokemon("Charmander", PokemonType::FIRE, 100);
            break;
        case PokemonChoice::BULBASAUR:
            chosenPokemon = Pokemon("Bulbasaur", PokemonType::GRASS, 100);
            break;
        case PokemonChoice::SQUIRTLE:
            chosenPokemon = Pokemon("Squirtle", PokemonType::WATER, 100);
            break;
        default:
            chosenPokemon = Pokemon("Pikachu", PokemonType::ELECTRIC, 100);
            break;
        }
        cout << "Player " << name << " chose " << chosenPokemon.name << "!" << endl;
        WaitforEnter();
    }
};

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
        WaitforEnter();
        cout << name << ": My name is Oak. People call me the Pokemon Professor!" << endl;
        WaitforEnter();
        cout << name << ": But enough about me. Let's talk about you!" << endl;
        WaitforEnter();
    }

    // Method to ask the player to choose a Pokemon
    void offerPokemonChoices(Player& player) {
        cout << name << ": First, tell me, what�s your name?" << endl;
        getline(cin, player.name);
        cout << name << ": Ah, " << player.name << "! What a fantastic name!" << endl;
        WaitforEnter();
        cout << name << ": You must be eager to start your adventure. But first, you�ll need a Pokemon of your own!" << endl;
        WaitforEnter();

        // Presenting Pokemon choices 
        cout << name << ": I have three Pokemon here with me. They�re all quite feisty!" << endl;
        WaitforEnter();
        cout << name << ": Choose wisely...\n"; cout << "1. Charmander - The fire type. A real hothead!" << endl;
        cout << "2. Bulbasaur - The grass type. Calm and collected!" << endl;
        cout << "3. Squirtle - The water type. Cool as a cucumber!" << endl;

        int choice;
        cout << name << ": So, which one will it be? Enter the number of your choice: ";
        cin >> choice;

        player.choosePokemon(choice);
        WaitforEnter();
    }

    // New method for the main quest conversation
    void explainMainQuest(Player& player) {
        clearConsole();

        cout << "Professor Oak: Ah, " << player.name << ", let me tell you about your grand adventure that's about to unfold!" << endl;
        WaitforEnter();
        cout << "Professor Oak: You see, becoming a Pok�mon Master is no easy feat. It takes courage, wisdom, and a bit of luck." << endl;
        WaitforEnter();
        cout << "Professor Oak: Your main mission is to collect all the Pok�mon Badges and defeat the Pok�mon League. Only then can you challenge the Elite Four and aim for the title of Champion." << endl;
        WaitforEnter();
        cout << player.name << ": Wait, isn�t that just like every other Pok�mon game?" << endl;
        WaitforEnter();
        cout << "Professor Oak: No breaking the fourth wall, " << player.name << "! This is serious business." << endl;
        WaitforEnter();
        cout << "Professor Oak: To achieve this, you must capture new Pok�mon, battle wild creatures, challenge gym leaders, and keep your Pok�mon healthy at the PokeCenter." << endl;
        WaitforEnter();
        cout << "Professor Oak: Remember, you can only carry a limited number of Pok�mon. Choose wisely who you want on your team!" << endl;
        WaitforEnter();
        cout << player.name << ": Piece of cake, right?" << endl;
        WaitforEnter();
        cout << "Professor Oak: Ha! That�s what everyone thinks. But the path to becoming a Champion is filled with obstacles. Lose a battle, and it�s back to the start!." << endl;
        WaitforEnter();
        cout << "Professor Oak: So, what do you say? Are you ready to embark on this epic journey to become the next Pok�mon Champion?" << endl;
        WaitforEnter();
        cout << player.name << ": Ready as I�ll ever be, Professor!" << endl;
        WaitforEnter();
        cout << "Professor Oak: That�s the spirit! Now, your journey begins. Remember, it�s not just about battling�it�s about forming bonds with your Pok�mon. Go, Trainer, the world of Pok�mon awaits you!" << endl;
        WaitforEnter();
        cout << "Professor Oak: Oh, and about the actual game loop� let�s just pretend I didn�t forget to set it up. Onwards!" << endl;
        WaitforEnter();
    }
};

// Function to handle the main game loop
void gameLoop(Player &player) {
    int choice;
    bool keepPlaying = true;

    while (keepPlaying) {
        clearConsole();

        // Display options to the player
        cout << "\nWhat would you like to do next, " << player.name << "?" << endl;
        cout << "1. Battle Wild Pok�mon" << endl;
        cout << "2. Visit PokeCenter" << endl;
        cout << "3. Challenge Gyms" << endl;
        cout << "4. Enter Pok�mon League" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the newline character left in the buffer after cin >> choice
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Process the player's choice and display the corresponding message
        switch (choice) {
        case 1:
            cout << "You look around... but all the wild Pok�mon are on vacation. Maybe try again later?" << endl;
            break;
        case 2:
            cout << "You head to the PokeCenter, but Nurse Joy is out on a coffee break. Guess your Pok�mon will have to tough it out for now!" << endl;
            break;
        case 3:
            cout << "You march up to the Gym, but it's closed for renovations. Seems like even Gym Leaders need a break!" << endl;
            break;
        case 4:
            cout << "You boldly step towards the Pok�mon League... but the gatekeeper laughs and says, 'Maybe next time, champ!" << endl;
            break;
        case 5:
            cout << "You try to quit, but Professor Oak's voice echoes: 'There's no quitting in Pok�mon training!'" << endl;
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
        
        WaitforEnter();
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

#include "header.hpp"