#ifdef WARRIOR_H
#define WARRIOR_H

#include "character.h"

using namespace std;

class Warrior : public Character{
    public:
        // constructor
        Warrior(const string& name);

        // destructor
        ~Warrior() override = default;

        //combate
        void basicAttack(Character& target) override;
        void specialAbility(Character& target) override;
        int calculateDamage() const override;

        // progresion
        void gainExoperience(int amount) override;
        void levelUp() override;

        // informacion
        void showStatus() const override;

}

#endif