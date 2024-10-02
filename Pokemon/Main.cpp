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
    ELECTRIC
};

// Pokemon class
class Pokemon {
public:
    // Data Members
    string name;
    PokemonType type;
    int health;

    // Constructors
    Pokemon() {

    }

    Pokemon(string p_name, PokemonType p_type, int p_health) {
        name = p_name;
        type = p_type;
        health = p_health;
    }

    // Attack Method
    void attack() {
        cout << name << "attacks with a powerful move!" << endl;
    }
};

// Player class
class Player {
public:
    // Data Members
    string name;
    Pokemon chosenPokemon;

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

    // Creating Objects of ProfessorOak, Pokemon and Player class
    ProfessorOak professor;
    Pokemon placeholderPokemon;
    Player player;

    //Assigning Values to placeholderPokemon attributes
    placeholderPokemon.name = "Pikachu";
    placeholderPokemon.type = PokemonType::ELECTRIC;
    placeholderPokemon.health = 40;

    //Assigning Values to player attributes
    player.name = "Trainer";

    //Assigning Values to ProfessorOak attributes
    professor.name = "Professor Oak";

    // Greet the player and offer Pokemon choices 
    professor.greetPlayer(player);
    professor.offerPokemonChoices(player);

    // Conclude the first chapter 
    cout << "Professor Oak: " << player.chosenPokemon.name << " and you, " << player.name << ", are going to be the best of friends!" << endl;
    cout << "Professor Oak: Your journey begins now! Get ready to explore the vast world of Pokemon!" << endl;


    return 0;

}