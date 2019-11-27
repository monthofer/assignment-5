/*
Sarah Monthofer
2317035
monthofer@chapman.edu
CPSC 350 - Assignment 5

Description: This file is supposed to do the 14 functions with the database
*/

#include <iostream>
#include "Menu.h"

using namespace std;

// constructor
Menu::Menu() {

}

// destructor
Menu::~Menu() {

}

void Menu::readFromFile() {
  // student variables
  int studentID = 0;
  string name = "";
  string grade = "";
  string major = "";
  double gpa = 0.0;
  int facultyAdvisorID = 0;

  // faculty variables
  int facultyID = 0;
  string name = "";
  string level = "";
  string department = "";
  int facultyAdviseesID = 0;
}

void Menu::printMenuOptions() {
  cout << "                 Database Options " << endl;
  cout << "---------------------------------------------------" << endl;
  cout << "1. Print all students and their information" << endl;
  cout << "2. Print all faculty and their information" << endl;
  cout << "3. Find and display student information" << endl;
  cout << "4. Find and display faculty information" << endl;
  cout << "5. Print the name and info of their faculty advisor" << endl;
  cout << "6. Print all the names and info of his/her advisees " << endl;
  cout << "7. Add a new student" << endl;
  cout << "8. Delete a student" << endl;
  cout << "9. Add a new faculty member" << endl;
  cout << "10. Delete a faculty member" << endl;
  cout << "11. Change a student’s advisor" << endl;
  cout << "12. Remove an advisee from a faculty member" << endl;
  cout << "13. Rollback" << endl;
  cout << "14. Exit" << endl;

  cout << endl;
  cout << endl;
  cout << "100 percent my time managment issues, but I did not have time to" << endl;
  cout << "work on the project so none of the menu options work" << endl;
}

void Menu::printAllStudentsInfo() {

}

void Menu::printAllFacultiesInfo() {

}
void Menu::displayStudentInfo() {

}

void Menu::displayFacultyInfo() {

}

void Menu::findFacultyAdvisor() {

}

void Menu::findFacultyAdvisees() {

}
void Menu::addStudent() {

}

void Menu::deleteStudent() {

}
void Menu::addFaculty() {

}

void Menu::deleteFaculty() {

}

void Menu::changeAdvisor() {

}
void Menu::removeAdvisee() {

}

void Menu::rollback() {

}

void Menu::exit() {
  cout << "You have Choosen to Exit" << endl;
  cout << "GoodBye" << endl;
  exit(1);
}
