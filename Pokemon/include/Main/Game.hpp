#pragma once
#include "../Character/Player/Player.hpp"
#include "../Pokemon/Grass.hpp"

// class Player;
namespace N_Main
{
  using namespace N_Pokemon;
  using namespace N_Character::N_Player;

  class Game {
  private:
    Grass forestGrass;
  public:
    Game();
    void gameLoop(N_Character::N_Player::Player &Player);
    void visitPokeCenter(N_Character::N_Player::Player &Player);
    // void gameLoop(Player &player);
    // void visitPokeCenter(Player &player); 
  };
}