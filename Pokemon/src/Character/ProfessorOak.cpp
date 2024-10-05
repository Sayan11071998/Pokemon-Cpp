#include "../../include/Character/ProfessorOak.hpp"
#include "../../include/Character/Player/Player.hpp"
#include "../../include/Utility/Utility.hpp"
#include <iostream>
using namespace std;

ProfessorOak::ProfessorOak(string p_name) {
    name = p_name;
}

// Method to greet the player
void ProfessorOak::greetPlayer(Player& player) {
    cout << name << ": Hello there! Welcome to the world of Pokemon!" << endl;
    Utility::waitforEnter();
    cout << name << ": My name is Oak. People call me the Pokemon Professor!" << endl;
    Utility::waitforEnter();
    cout << name << ": But enough about me. Let's talk about you!" << endl;
    Utility::waitforEnter();
}

// Method to ask the player to choose a Pokemon
void ProfessorOak::offerPokemonChoices(Player& player) {
    cout << name << ": First, tell me, what�s your name?" << endl;
    getline(cin, player.name);
    cout << name << ": Ah, " << player.name << "! What a fantastic name!" << endl;
    Utility::waitforEnter();
    cout << name << ": You must be eager to start your adventure. But first, you�ll need a Pokemon of your own!" << endl;
    Utility::waitforEnter();

    // Presenting Pokemon choices 
    cout << name << ": I have three Pokemon here with me. They�re all quite feisty!" << endl;
    Utility::waitforEnter();
    cout << name << ": Choose wisely...\n"; cout << "1. Charmander - The fire type. A real hothead!" << endl;
    cout << "2. Bulbasaur - The grass type. Calm and collected!" << endl;
    cout << "3. Squirtle - The water type. Cool as a cucumber!" << endl;

    int choice;
    cout << name << ": So, which one will it be? Enter the number of your choice: ";
    cin >> choice;

    player.choosePokemon(choice);
    Utility::waitforEnter();
}

// New method for the main quest conversation
void ProfessorOak::explainMainQuest(Player& player) {
    Utility::clearConsole();

    cout << "Professor Oak: Ah, " << player.name << ", let me tell you about your grand adventure that's about to unfold!" << endl;
    Utility::waitforEnter();
    cout << "Professor Oak: You see, becoming a Pok�mon Master is no easy feat. It takes courage, wisdom, and a bit of luck." << endl;
    Utility::waitforEnter();
    cout << "Professor Oak: Your main mission is to collect all the Pok�mon Badges and defeat the Pok�mon League. Only then can you challenge the Elite Four and aim for the title of Champion." << endl;
    Utility::waitforEnter();
    cout << player.name << ": Wait, isn�t that just like every other Pok�mon game?" << endl;
    Utility::waitforEnter();
    cout << "Professor Oak: No breaking the fourth wall, " << player.name << "! This is serious business." << endl;
    Utility::waitforEnter();
    cout << "Professor Oak: To achieve this, you must capture new Pok�mon, battle wild creatures, challenge gym leaders, and keep your Pok�mon healthy at the PokeCenter." << endl;
    Utility::waitforEnter();
    cout << "Professor Oak: Remember, you can only carry a limited number of Pok�mon. Choose wisely who you want on your team!" << endl;
    Utility::waitforEnter();
    cout << player.name << ": Piece of cake, right?" << endl;
    Utility::waitforEnter();
    cout << "Professor Oak: Ha! That�s what everyone thinks. But the path to becoming a Champion is filled with obstacles. Lose a battle, and it�s back to the start!." << endl;
    Utility::waitforEnter();
    cout << "Professor Oak: So, what do you say? Are you ready to embark on this epic journey to become the next Pok�mon Champion?" << endl;
    Utility::waitforEnter();
    cout << player.name << ": Ready as I�ll ever be, Professor!" << endl;
    Utility::waitforEnter();
    cout << "Professor Oak: That�s the spirit! Now, your journey begins. Remember, it�s not just about battling�it�s about forming bonds with your Pok�mon. Go, Trainer, the world of Pok�mon awaits you!" << endl;
    Utility::waitforEnter();
    cout << "Professor Oak: Oh, and about the actual game loop� let�s just pretend I didn�t forget to set it up. Onwards!" << endl;
    Utility::waitforEnter();
}