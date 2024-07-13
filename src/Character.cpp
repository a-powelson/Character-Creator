#include "Character.h"

/*
    Aggregation relationship for Characters and Pets
    since Pets can exist outside their owners.
*/

Character::Character(string nm, string desc, string emj, Pet *pt) {
    name = nm;
    description = desc;
    emoji = emj;
    pet = pt;
}

Character::Character() {
    name = "";
    description = "";
    emoji = "";
    pet = nullptr;
}

void Character::print() {
    if(pet != nullptr) {
        cout << "Meet " + name + " " + emoji + ". " + description + " " 
                + name + " has a pet " +  pet->getType() + " named "
                + pet->getName() + " " + pet->getEmoji() + ".\n\n";
    } else {
        cout << "Meet " + name + " " + emoji + ". " + description + "\n\n";
    }
}

void Character::setName(string nm) { name = nm; }
void Character::setDesc(string desc) { description = desc; }
void Character::setEmoji(string emj) { emoji = emj; }
void Character::setPet(Pet *pt) {pet = pt; }

string Character::getName() { return name; }
string Character::getDesc() { return description; }
string Character::getEmoji() { return emoji; }
Pet* Character::getPet() { return pet; }