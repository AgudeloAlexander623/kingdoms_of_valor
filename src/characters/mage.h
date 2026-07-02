#ifdef MAGE_H
#define MAGE_H

#include "character.h"

using namespace std;

class Mage : public Character {
    public:
    //constructor
        Mage(const string& name);

    // destructor
        ~Mage() override = default;

    // combate
        void basicAttack(Character& target) override;
        void specialAbility(Character& target) override;
        int calculateDamage() const override;

    // Progression
        void gainExperience(int amount) override;
        void levelUp() override;

    // informacion
        void showStatus() const override;

};

#endif