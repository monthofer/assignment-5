/*
Sarah Monthofer
2317035
monthofer@chapman.edu
CPSC 350 - Assignment 5

Description: header file for menu
*/


#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

class Menu {
  public:

    // constuctor and destructor
    Menu();
    ~Menu();

    // menu methods
    void readFromFile();
    void printMenuOptions();
    void printAllStudentsInfo();
    void printAllFacultiesInfo();
    void displayStudentInfo();
    void displayFacultyInfo();
    void findFacultyAdvisor();
    void findFacultyAdvisees();
    void addStudent();
    void deleteStudent();
    void addFaculty();
    void deleteFaculty();
    void changeAdvisor();
    void removeAdvisee();
    void rollback();
    void exit();
};
