#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

using namespace std;

class Character{
    protected:
        // nombre del pesonaje, ingresado por el usuario, informacion basica
        string name;
        string CharacterClass;
        
        //nivel del personaje
        int level;
        int experience;

        // vida del personaje
        int health;
        int maxHealth;
        
        // mana del personaje
        int mana;
        int maxMana;

        // funciones basicas
        int attack;
        int defence;
        int speed;

    public:
        Character
        (
            const string& name,
            const string& CharacterClass,
            int health,
            int mana,
            int attack,
            int defence,
            int speed
        );

        virtual ~Character() = default;

        // combate
        virtual void basicAttack(Character& target);
        virtual void specialAbility(Character& target) = 0;
        virtual int calculateDamage() = 0;
        virtual void receiveDamage(int damage);
        virtual void heal(int amount);
        virtual bool spendMana(int amount);
        virtual void restoreMana(int amount);

        // progresión
        void gainExperience(int amount);
        void levelUp();

        // Estado
        bool isAlive() const;
        virtual void showStatus() const;

        // Getters
        string getName() const;
        string getCharacterClass() const;
        int getHealth() const;
        int getMaxHealth() const;
        int getMana() const;
        int getMaxMana() const;
        int getAttack() const;
        int getDefense() const;
        int getSpeed() const;
        int getLevel() const;
        int getExperience() const;
        int getExperienceToNextLevel() const;
};

#endif