#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

using namespace std;

class Character {
public:
    Character(const string& name, const string& characterClass, int maxHealth, int maxMana, int attack, int defence, int speed);
    virtual ~Character();

    const string& getName() const;
    const string& getCharacterClass() const;
    int getLevel() const;
    int getExperience() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getMana() const;
    int getMaxMana() const;
    int getAttack() const;
    int getDefence() const;
    int getSpeed() const;

    void receiveDamage(int damage);
    bool spendMana(int amount);
    void gainExperience(int exp);
    virtual void levelUp();
    virtual void showStatus() const;

protected:
    int calculateDamage() const;

protected:
    string name;
    string characterClass;
    int level;
    int experience;
    int health;
    int maxHealth;
    int mana;
    int maxMana;
    int attack;
    int defence;
    int speed;
};

#endif // CHARACTER_H