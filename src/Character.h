#ifndef CHAR_HEADER
#define CHAR_HEADER

#include <iostream>
#include "Pet.h"
using namespace std;

class Character {
    private:
        string name;
        string description;
        string emoji;
        Pet* pet;
    public:
        Character(string, string, string, Pet*);
        Character();
        void print();
        void setName(string);
        void setDesc(string);
        void setEmoji(string);
        void setPet(Pet*);
        string getName();
        string getDesc();
        string getEmoji();
        Pet* getPet();
};

#endif