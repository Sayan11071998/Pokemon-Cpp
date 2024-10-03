#include<iostream>
#include<string>
using namespace std;

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
        name = "Pikachu";
        type = PokemonType::ELECTRIC;
        health = 10;
        cout << "A new Pokemon has been created with the default constructor!" << endl;
    }
    // Parameterized Constructors
    Pokemon(string p_name, PokemonType p_type, int p_health) {
        name = p_name;
        type = p_type;
        health = p_health;
        cout << "A new Pokemon named " << name << " has been created!" << endl;
    }
    // Copy constructor
    Pokemon(const Pokemon &other) {
        name = other.name;
        type = other.type;
        health = other.health;
        cout << "A new Pokemon has been copied from " << other.name << "!" << endl;
    }

    // Destructor
    ~Pokemon() {
        cout << name << " has been released." << endl;
    }

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
        cout << "A new player named " << name << " has been created!" << endl;
    }
    // Parameterized Constructors
    Player(string p_name, Pokemon p_chosenPokemon) {
        name = p_name;
        chosenPokemon = p_chosenPokemon;
        cout << "Player " << name << " has been created!" << endl;
    }
    // Copy constructor
    Player(const Player& other) {
        name = other.name;
        chosenPokemon = other.chosenPokemon;
        cout << "A new player has been copied from " << other.name << "!" << endl;
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
        cout << name << ": My name is Oak. People call me the Pokemon Professor!" << endl;
        cout << name << ": But enough about me. Let's talk about you!" << endl;
    }

    // Method to ask the player to choose a Pokemon
    void offerPokemonChoices(Player& player) {
        cout << name << ": First, tell me, what’s your name?" << endl;
        getline(cin, player.name);
        cout << name << ": Ah, " << player.name << "! What a fantastic name!" << endl;
        cout << name << ": You must be eager to start your adventure. But first, you’ll need a Pokemon of your own!" << endl;

        // Presenting Pokemon choices 
        cout << name << ": I have three Pokemon here with me. They’re all quite feisty!" << endl;
        cout << name << ": Choose wisely...\n"; cout << "1. Charmander - The fire type. A real hothead!" << endl;
        cout << "2. Bulbasaur - The grass type. Calm and collected!" << endl;
        cout << "3. Squirtle - The water type. Cool as a cucumber!" << endl;

        int choice;
        cout << name << ": So, which one will it be? Enter the number of your choice: ";
        cin >> choice;
        player.choosePokemon(choice);
    }
};

int main() {

    // Task 1: Test default and parameterized constructors
    Pokemon defaultPokemon; // Using default constructor
    Pokemon charmander("Charmander", PokemonType::FIRE, 100); // Using parameterized constructor

    cout << "Pokemon Details:" << endl;
    cout << "Name: " << defaultPokemon.name << "\nType: " << (int)defaultPokemon.type << "\nHealth: " << defaultPokemon.health << endl;
    cout << "Name: " << charmander.name << "\nType: " << (int)charmander.type << "\nHealth: " << charmander.health << endl;

    // Task 2: Test the copy constructor
    Pokemon bulbasaur("Bulbasaur", PokemonType::GRASS, 100); // Create a Pokemon
    Pokemon bulbasaurCopy = bulbasaur; // Copy the Pokemon
    cout << "Original Pokemon Health: " << bulbasaur.health << endl;
    cout << "Copied Pokemon Health: " << bulbasaurCopy.health << endl;

    // Modify the copy
    bulbasaurCopy.health = 80;
    cout << "After Modification:" << endl;
    cout << "Original Pokemon Health: " << bulbasaur.health << endl;
    cout << "Copied Pokemon Health: " << bulbasaurCopy.health << endl;

    // Task 3: Test the destructor
    {
        Pokemon squirtle("Squirtle", PokemonType::WATER, 100); // Pokemon will be destroyed at the end of this scope
    } // Destructor will be called here

    // Continue with the main flow of the game
    ProfessorOak professor("Professor Oak");
    Player player("Ash", charmander);

    // Greet the player and offer Pokemon choices
    professor.greetPlayer(player);
    professor.offerPokemonChoices(player);

    // Conclude the first chapter
    cout << "Professor Oak: " << player.chosenPokemon.name << " and you, " << player.name << ", are going to be the best of friends!" << endl;
    cout << "Professor Oak: Your journey begins now! Get ready to explore the vast world of Pokemon!" << endl;


    return 0;

}