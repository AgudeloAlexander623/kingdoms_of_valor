#ifdef ARCHER_H
#define ARCHER_H

#include "character.h"

using namespace std;

class Archer : public Character {
    public:
        // constructor
        Archer(const string& name); 

        // destructor
        ~Archer() override = default;

        // combate
        void basicAttack(character& target) override;
        void specialAbility(character& target) override;
        int calculateDamage() const override;

        // progresion
        void gainExperience(int amount) override;
        void levelUp() override;

        // informacion
        void showSatatus() const override;
};

#endif