#include "archer.h"
#include <iostream>

using namespace std;

//constructor
Archer::Archer(const string& name)
    : Character(
        name,
        "Archer",
        100,   //vida
        60,   //Mana
        12,    //ataque
        7,     //defensa
        18      //velocidad
    ) 
{ 
}

// ataque basico
void Archer::basicAttack(Character& target){
    int damage = calculateDamage();

    cout << endl;
    cout << getName()
        << " shoots an arrow at "
        << target.getName()
        << "."
        << endl;

    target.receiveDamage(damage);

    cout << target.getName()
        << " receives "
        << damage
        << " damage."
        << endl;    
}

// habilidad especial
void Archer::specialAbility(Character& target){
    const int manaCost = 15;

    if (! spendMana(manaCost)){
        cout << endl;
        cout << getName()
            << " does not have enough mana to use power Shot."
            << endl;
        return;
    }
    int damage = calculateDamage() * 2;

    cout << endl;
    cout << getName()
        << " uses Power Shot "
        << endl;

    target.receiveDamage(damage);
    cout << target.getName()
        << " receives "
        << damage
        << " damage. "
        << endl;
}

// calcular daño
int Archer::calculateDamage() const{
    return getAttack() + (getLevel() * 2);
}

// ganar experiencia
void Archer::gainExperience(int amount){
    experience += amount;

    // verificar si el arquero sube de nivel
    // umbral de experiencia: nivel actual * 100
    while (experience >= getLevel() * 100){
        experience -= getLevel() * 100;
        levelUp();
    }
}

// subida de nivel
void Archer::levelUp(){
    Character::levelUp();

    maxHealth += 10;
    maxMana += 8;

    attack += 3;
    defence += 2;
    speed += 2;

    health = maxHealth;
    mana = maxMana;

    cout << endl;
    cout << "Archer statistics increased" << endl; 
}

// mostrar estado
void Archer::showStatus() const{

    cout << endl;
    cout << "Name: " << getName() << endl;
    cout << "Class: " << getCharacterClass() << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "Experience: " << getExperience() << endl;
    cout << "Health: " << getHealth() << "/" << getMaxHealth() << endl;
    cout << "Mana: " << getMana() << "/" << getMaxMana() << endl;
    cout << "Attack: " << getAttack() << endl;
    cout << "Defense: " << getDefence() << endl;
    cout << "Speed: " << getSpeed() << endl;

}