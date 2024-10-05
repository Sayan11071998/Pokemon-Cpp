#include "Pokemon.hpp"
#include "Player.hpp"
#include "BattleState.hpp"

class BattleManager {
public:
	void startBattle(Player& player, Pokemon& wildPokemon);
private:
	BattleState battleState;

	void battle(Pokemon& playerPokemon, Pokemon& wildPokemon);
	void handleBattleOutcome(Player& player, bool playerWon);
	void updateBattleState();
};