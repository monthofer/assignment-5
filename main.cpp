/*
Sarah Monthofer
2317035
monthofer@chapman.edu
CPSC 350 - Assignment 5

Description: main file to call other files and methods
*/

#include <iostream>
#include "Menu.h"

using namespace std;

int main(int argc, char** argv) {
  Menu menu;

  menu.readFromFile();
  menu.printMenuOptions();
}
