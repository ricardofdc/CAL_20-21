//
// Created by ricar on 12/05/2021.
//

#ifndef PROJETO_MENU_H
#define PROJETO_MENU_H


#include <iostream>
#include <vector>

using namespace std;

typedef void(*menuFunctionPtr)();


void drawMenu(const string& menuTitle, vector<pair<string, menuFunctionPtr> > menuItems);
unsigned int getUnsignedIntInputInclusive(unsigned int lowerBound, unsigned int higherBound, string errorMsg);



#endif //PROJETO_MENU_H
