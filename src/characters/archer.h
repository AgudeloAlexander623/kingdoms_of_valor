#ifndef ARCHER_H
#define ARCHER_H

#include "character.h"

class Archer : public Character {
    public:
        // constructor
        Archer(const std::string& name); 

        // destructor
        ~Archer() override = default;

        // combate
        void basicAttack(Character& target) override;
        void specialAbility(Character& target) override;
        int calculateDamage() const override;

        // progresion
        void gainExperience(int amount);
        void levelUp() override;

        // informacion
        void showStatus() const override;
};

#endif