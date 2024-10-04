#include <string>
enum class PokemonType;
using namespace std;

class Pokemon {
public:
    string name;
    PokemonType type;
    int health;
    int maxHealth;
    int attackPower;

    Pokemon();
    Pokemon(string p_name, PokemonType p_type, int p_health);
    Pokemon(const Pokemon& other);

    ~Pokemon();

    void attack(Pokemon &target);
    void takeDamage(int damage);
    bool isFainted() const;
    void heal();
};