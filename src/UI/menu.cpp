//
// Created by ricar on 12/05/2021.
//

#include "menu.h"

/**
 * Draws menu items and calls getUnsignedIntInputInclusive() for input.
 *
 * @param const string& menuTitle
 * @param vector<pair<string, menuFunctionPtr> > menuItems
 * @return void
 */
void drawMenu(const string& menuTitle, vector<pair<string, menuFunctionPtr> > menuItems){

    string errorMsg = "Invalid Input. Insert a value beetween 0 and " + to_string(menuItems.size()) + "\n";

    while (true) {

        int selectedItem = -1;
        cout << "\n ------ " << menuTitle << " ------\n\n + - - - - - - - -\n |\n";
        for (int i = 0; i < menuItems.size(); i++) {
            cout << " | " << i + 1 << " - " << menuItems[i].first << "\n |\n";
        }
        cout << " | 0 - Back\n |\n + - - - - - - - -\n\n---------------------------------------------------- \n\n";

        cout << "Please insert a value between 0 and " + to_string(menuItems.size()) + "\n";

        selectedItem = getUnsignedIntInputInclusive(0, menuItems.size(), errorMsg);

        if (selectedItem == 0) {
            break;
        } else {
            menuItems[selectedItem - 1].second();
        }
    }
}

/**
 * Loops until input between lower and upper bound is received.
 *
  * @param unsigned int lowerBound
  * @param unsigned int higherBound
  * @param string errorMsg
  * @return unsigned int
 */
unsigned int getUnsignedIntInputInclusive(unsigned int lowerBound, unsigned int higherBound, string errorMsg){
    int result;
    cin >> result;
    while(!cin.good() || result < lowerBound || result > higherBound){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << errorMsg << endl;
        cin >> result;
    }
    cin.ignore(1000, '\n');
    return result;
}
