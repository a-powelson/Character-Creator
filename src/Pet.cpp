#include "Pet.h"

Pet::Pet(string tp, string nm, string emj) {
    type = tp;
    name = nm;
    emoji = emj;
}

Pet::Pet() {
    type = "";
    name = "";
    emoji = "";
}

void Pet::setType(string tp) { type = tp; }
void Pet::setName(string nm) { name = nm; }
void Pet::setEmoji(string emj) { emoji = emj; }

string Pet::getType() { return type; }
string Pet::getName() { return name; }
string Pet::getEmoji() { return emoji; }