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
    cout << name
        << " shoots an arrow at "
        << target.getName()
        << "."
        << endl;

    target.receiveDamage(damage);

    cout << target.getName()
        << "receives"
        << damage
        << "damage."
        << endl;    
}

// habilidad especial
void Archer::specialAbility(Character& target){
    const int manaCost = 15;

    if (! spendMana(manaCost)){
        cout << endl;
        cout << name
            << " does not have enough mana to use power Shot."
            << endl;
        return;
    }
    int damage = calculateDamage() * 2;

    cout << endl;
    cout << name
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
    return attack + (level * 2);
}

// subida de nivel
void Archer::levelUp(){
    Characters::levelUp();

    maxHealth += 10;
    maxMana += 8;

    attack += 3;
    defence += 2;
    speed += 2;\

    health = maxHealth;
    mana = maxMana;

    cout << endl;
    cout << "Archer statistics increased" << endl; 
}

// mostrar estado
void Archer::showStatus() const{

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