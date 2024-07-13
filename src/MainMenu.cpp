#include "Menu.h"

int main() {
    Menu *m = new Menu();

    bool close = false;
    do {
        m->printMainMenu();
        int response; 
        cin >> response;
        if(cin) {
            close = m->handleMenuSelection(response);
        }
        else {
            cin.clear();
            cin.ignore();
            cout << "\nInvalid selection, please try again.\n\n";
        }
    } while (!close);

    return 0;
}