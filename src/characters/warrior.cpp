#include "warrior.h"
#include <iostream>

using namespace std;

// constructor
Warrior::Warrior(const string& name)
    : Character(
        name,
        "Warrior",
        150,   // vida
        40,    // mana
        18,    // ataque
        15,    // defensa
        8     // velocidad
    )
{
}

// ataque basico
void Warrior::basicAttack(Character& target){
    int damage = calculateDamage();

    cout << endl;
    cout << name
        << " swings a sword at "
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
void Warrior::specialAbility(Character& target){
    const int manaCost = 20;

    if (!spendMana(manaCost)){
        cout << endl;
        cout << name
            << " does not have enough mana to use Heavy Strike. "
            << endl;
        return;

    }
    int damage = calculateDamage() * 2;

    cout << endl;
    cout << name
        << " uses Heavy strike "
        << endl;
    
    target.receiveDamage(damage);

    cout << target.getName()
        << " receives "
        << damage
        << " damage. "
        << endl;
}

// calcular daño
int Warrior::calculateDamage() const{
    return attackPower + (defence / 2) + level;
}

// subida de nivel

void Warrior::levelUp()
{
    Character::levelUp();

    maxHealth += 15;
    maxMana += 5;

    attack += 4;
    defense += 3;
    speed += 1;

    health = maxHealth;
    mana = maxMana;

    cout << endl;
    cout << "Warrior statistics increased" << endl
}

// mostrar estadisticas
void Warrior::showStatus() const{
    cout << endl;
    cout << "Name: " << name << endl;
    cout << "Class: " << CharacterClass << endl;
    cout << "Level: " << level << endl;
    cout << "Experience: " << experience << endl;
    cout << "Health: " << health << "/" << maxHealth << endl;
    cout << "Mana: " << mana << "/" << maxMana << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defence << endl;
    cout << "Speed: " << speed << endl;

}