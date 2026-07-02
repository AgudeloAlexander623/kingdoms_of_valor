#include "mage.h"
#include <iostream>

using namespace std;

//constructor
Mage::Mage(const string& name)
   : Character(
    name, 
    "Mage", 
    80,     //vida
    120,    //Mana
    15,     //ataque
    5,      //defensa
    10)     //velocidad
   {} 

//ataque basico
void Mage::basicAttack(Character& target){
    int damage = calculateDamage();

        cout << endl;
        cout << name << " attacks " << target.getName()
             << " with the magic staff." << endl;

        target.receiveDamage(damage);

        cout << target.getName()
            << " receives "
            << damage
            << " damage."
            << endl;
} 

// gabilidad especial
void Mage::specialAbility(Character& target){
    const int manaCost = 30;

    if (!spendMana(manaCost)){
        cout << endl;
        cout << name
            << " does not have enough mana to cast Fireball."
            << endl;
        return;
    }
    int damage = calculateDamage() *2;

    cout << endl;
    cout << name
        << "casts Fireball on "
        << endl;
    
    target.receiveDamage(damage);

    cout << target.getName()
        << "receives"
        << damage
        << "magic damage."
        << endl;
}

// calcular daño
int Mage::calculateDamage() const{
    return attack + (level * 2);
}

// progresión
void Mage::gainExperience(int amount){
    Character::levelUp();

    maxHealth += 8;
    maxMana += 15;

    attack += 2;
    defence += 1;
    speed += 1;

    health = maxHealth;
    mana = maxMana;

    cout << endl;
    cout << "mage statistics increased"
        << endl;
}

// mostrar estadisticas
void Mage::showStatus() const{
    cout << endl;
    cout << "Character: " << name << endl;
    cout << "Class: " << characterClass << endl;
    cout << "Level: " << level << endl;
    cout << "Experience: " << experience << "/" << getExperienceToNextLevel() << endl;
    cout << "Health: " << health << "/" << maxHealth << endl;
    cout << "Mana: " << mana << "/" << maxMana << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defence << endl;
    cout << "Speed: " << speed << endl;
}