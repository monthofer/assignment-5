/*
Sarah Monthofer
2317035
monthofer@chapman.edu
CPSC 350 - Assignment 5
*/

#include <iostream>

using namespace std;

template <class T>
class TreeNode {
  public:
    // variables and pointers
    T* data;
    int key;
    TreeNode<T> *left;
    TreeNode<T> *right;

    // constructors and destructors
    TreeNode();
    TreeNode(T* d, int k);
    ~TreeNode();
};

// default constructor
template <class T>
TreeNode<T>::TreeNode() {
  data = d;
  key = -1;
  left = NULL;
  right = NULL;
}

// overload constructor
template <class T>
int TreeNode<T>::TreeNode(T* d, int k) {
  data = d;
  key = k;
  left = NULL;
  right = NULL;
}

// destructor
template <class T>
TreeNode<T>::~TreeNode() {
  delete left;
  delete right;
  delete data;
}