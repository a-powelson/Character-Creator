#include "Menu.h"

Menu::Menu() {
    characterList = vector<Character*>();

    emojis[0] = "\U0001F64D";
    emojis[1] = "\U0001F646";
    emojis[2] = "\U0001F481";
    emojis[3] = "\U0001F9CF";
    emojis[4] = "\U0001F9D1";
    emojis[5] = "\U0001F483";

    pets[0][0] = "None";
    pets[1][0] = "Cat";
    pets[2][0] = "Dog";
    pets[3][0] = "Orangutan";
    pets[4][0] = "Lizard";
    pets[5][0] = "Bird";
    pets[6][0] = "Dragon";

    pets[0][1] = "";
    pets[1][1] = "\U0001F408";
    pets[2][1] = "\U0001F415";
    pets[3][1] = "\U0001F9A7";
    pets[4][1] = "\U0001F98E";
    pets[5][1] = "\U0001F99C";
    pets[6][1] = "\U0001F409";
}

void Menu::printMainMenu() {
        cout << "Main Menu\n";
        cout << "1. Create New Character\n";
        cout << "2. View a Character\n";
        cout << "3. Delete a Character\n";
        cout << "4. Quit\n";
}

void Menu::printEmojiList() {
    for(int i=0; i<6; i++) {
        cout << to_string(i+1) + ". " + emojis[i] + "\n";
    }
}

void Menu::printPetList() {
    for(int i=0; i<7; i++) {
        cout << to_string(i+1) + ". " + pets[i][0] + "\n";
    }
}

void Menu::newCharacter() {
    string name, desc, emj, pet, petName;
    int emjNum, petNum;
    cin.ignore();

    cout << "Please enter a character name:\n";
    getline(cin, name);
    cout << "Please enter a character description:\n";
    getline(cin, desc);
    cout << "Please choose an emoji:\n";
    printEmojiList();
    getline(cin, emj);
    emjNum = stoi(emj) - 1;
    if(emjNum > 5 || !cin) {
        cout << "\nInvalid selection, please try again.\n\n";
        return;
    }
    cout << "Please choose a pet:\n";
    printPetList();
    getline(cin, pet);
    petNum = stoi(pet) - 1;
    if(petNum > 5 || !cin) {
        cout << "\nInvalid selection, please try again.\n\n";
        return;
    }

    Character *c;

    if(petNum == 0) {
        c = new Character(name, desc, emojis[emjNum], nullptr);
    }
    else {
        cout << "Please enter a name for your pet:\n";
        getline(cin, petName);

        Pet *p = new Pet(pets[petNum][0], petName, pets[petNum][1]);
        c = new Character(name, desc, emojis[emjNum], p);
    }

    characterList.push_back(c);
    cout << "\n";
    c->print();
}

void Menu::viewCharacter() {
    if(characterList.size() == 0) {
        cout << "There are no characters to view.\n\n";
        return;
    }

    cout << "Enter the number of the character you would like to view:\n";
    for(int i=0; i<characterList.size(); i++) {
        cout << to_string(i+1) + ". " + characterList.at(i)->getName()
                        + " " + characterList.at(i)->getEmoji() + "\n";
    }
    
    int n;
    cin >> n;

    if(n > characterList.size() || !cin) {
        cout << "\nInvalid selection, please try again.\n\n";
        cin.clear();
        cin.ignore();
        return;
    }

    cout << "\n";
    characterList.at(n-1)->print();
}

void Menu::deleteCharacter() {
     if(characterList.size() == 0) {
        cout << "There are no characters to delete.\n\n";
        return;
    }

    cout << "Enter the number of the character you would like to delete:\n";
    for(int i=0; i<characterList.size(); i++) {
        cout << to_string(i+1) + ". " + characterList.at(i)->getName() 
                        + " " + characterList.at(i)->getEmoji() + "\n";
    }
    
    int nChar, conf;
    cin >> nChar;

    if(nChar > characterList.size() || !cin) {
        cout << "\nInvalid selection, please try again.\n\n";
        cin.clear();
        cin.ignore();
        return;
    }

    string name = characterList.at(nChar-1)->getName();
    cout << "\nAre you sure you want to delete " + name + "?\n";
    cout << "1. No\n2. Yes\n";
    cin >> conf;
    
    if(conf == 1) {
        cout << "\nOkay, " + name + " has not been deleted.\n\n";
        return;
    }
    else if(conf == 2){
        characterList.erase(characterList.begin() + nChar - 1);
        cout << "\nOkay, " + name + " has been deleted.\n\n";
    }
    else {
        cout << "\nInvalid selection, please try again.\n\n";
        return;
    }

}

bool Menu::handleMenuSelection(int n) {
    switch (n) {
        case 1:
            cout << "\n";
            newCharacter();
            break;
        case 2:
            cout << "\n";
            viewCharacter();
            break;
        case 3:
            cout << "\n";
            deleteCharacter();
            break;
        case 4:
            return true;
        default:
            cout << "\nInvalid selection, please try again.\n\n";  
        }
    return false;
}