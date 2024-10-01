#include <iostream>
using namespace std;

int main()
{
    // Getting Player's Name
    string player_name;
    std::cout << "Enter your name: ";
    cin >> player_name;
    cout << "Ah, " << player_name << "!" << endl;
    
    // Meeting Professor Oak and choosing Pokemon
    cout << "Welcome to the world of Pokemon! I am Professor Oak." << endl;
    cout << "Today is a momentous day—you will be choosing your very first Pokémon." << endl;
    cout << "Every great Trainer remembers this moment for the rest of their lives." << endl;
    cout << "So, choose wisely, young one!" << endl;
    cout << "You can choose one of the following Pokémon: " << endl;
    cout << "1. Bulbasaur\n2. Charmander\n3. Squirtle\n";
    cout << "Which Pokémon would you like to choose? Enter the number: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "You chose Bulbasaur! A wise choice." << endl;
    }
    else if (choice == 2) {
        cout << "You chose Charmander! A fiery choice" << endl;
    }
    else if (choice == 3) {
        cout << "You chose Squirtle! A cool choice." << endl;
    }
    else {
        cout << "Invalid choice. Please restart the game." << endl;
    }
    
    // Words from professor Oak after choosing Poekmon
    cout << "Ah, an excellent choice!" << endl;
    cout << "But beware, Trainer, this is only the beginning. Your journey is about to unfold." << endl;
    cout << "Now let’s see if you’ve got what it takes to keep going!" << endl;
    cout << "Good luck, and remember… Choose wisely!" << endl;

    return 0;
}