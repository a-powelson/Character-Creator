#ifndef MENU_HEADER
#define MENU_HEADER

#include "Character.h"
#include <vector>

/*
    - Using vector for list of characters as more operations
    are done to access individual indices than to resize, though
    both operations are needed
    - Using arrays for emojis and pet lists as they will
    not change size and need to access via indices
*/

class Menu {
    private:
        vector<Character*> characterList;
        string emojis[6];
        string pets[7][2];
    public:
        Menu();
        void printMainMenu();
        void printEmojiList();
        void printPetList();
        void newCharacter();
        void viewCharacter();
        void deleteCharacter();
        bool handleMenuSelection(int);
};

#endif