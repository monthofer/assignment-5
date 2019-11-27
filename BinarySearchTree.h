/*
Sarah Monthofer
2317035
monthofer@chapman.edu
CPSC 350 - Assignment 5

Description: generic binary search tree template class
*/

#include <iostream>
#include <TreeNode.h>

using namespace std;

template <class T>
class BinarySearchTree {
protected:
    TreeNode<T> *root;
    int size;
    string d;

  public:
    // constructor and destructor
    BinarySearchTree();
    ~BinarySearchTree();

    // functions of Binary Search Tree
    bool contains(int k);
    T* find(int k);
    TreeNode<T>* getPreviousNode(TreeNode<T> *d);
    void insert(TreeNode<T> *node);
    bool remove(int k);
    void printRecursively(TreeNode<T> *node);
    void printTree();
    T* getMin();
    T* getMax();
    TreeNode<T>* getRoot();
    int getSize();
    bool isEmpty();
};

// default constuctor for Binary Search Tree
template <class T>
BinarySearchTree<T>::BinarySearchTree(){
  root = NULL;
  size = 0;
}

// default destructor for binary search tree
template <class T>
BinarySearchTree<T>::~BinarySearchTree(){

}

// check if the tree contians a node
template <class T>
bool BinarySearchTree<T>::contains(int k) {
  if(root == NULL) {
      return false;
  }

  // create pointer to the current node
  TreeNode<T> *curr = root;

  //iterate through the nodes until the current equals the node desired to find
  // if the node exists in the data the boolean will return true
  while(curr->key != k) {
    // if the node is smaller than root look on left
    if(k < curr->key) {
      curr = curr->left;
    }
    // if the node is larger than the root look on right
    else {
      curr = curr->right;
    }
    // return false if node is not found on either side
    if(curr == NULL) {
      return false;
    }
  }
  return true;
}

// find an existing node in the tree
template <class T>
T* BinarySearchTree<T>::find(int k) {
  // cannot find if the tree does not exist
  if (root == NULL) {
    return NULL;
  }

  if (contains(k)) {
    // create pointer to the current node
    TreeNode<T> *curr = root;

    //iterate through the nodes until the current equals the node desired to find
    while(curr->key != k) {
      // if the node is smaller than root look on left
      if(k < curr->key) {
        curr = curr->left;
      }
      // if the node is larger than the root look on right
      else {
        curr = curr->right;
      }
      // return false if node is not found on either side
      if(curr == NULL) {
        return NULL;
      }
    }
    // pointer to the data we were looking to find
    return curr->data;
  }
}

// find the previous node in the tree from the current node sent in
template <class T>
TreeNode<T>* BinarySearchTree<T>::getPreviousNode(TreeNode<T> *d) {
  TreeNode<T> *previous = d;
  TreeNode<T> *curr = d->right;

  // find the previous nond in the tree
  while(curr != NULL) {
    previous = curr;
    curr = curr->left;
  }

  return previous;
}

// insert a node into the tree
template <class T>
void BinarySearchTree<T>::insert(treeNode<T> *node) {
  // make sure tree is not empty
  if (root == NULL) {
    root = node;
  }

  else {
    // create pointers to current node and parent node
    TreeNode<T> *curr = root;
    TreeNode<T> *parent;

    while(true) {
      parent = curr;
      if(node->key < curr->key) {
        curr = curr->left;
        if(curr == NULL) {
            parent->left = node;
            break;
        }
      }
      else {
        if(node->key > curr->key) {
        curr = curr->right;
          if(curr == NULL) {
            parent->right = node;
            break;
          }
        }
      }
    }
  }
  ++size;
}

// delete a specific node from the tree
template <class T>
bool BinarySearchtree<T>::remove(int k) {
  // make sure tree is not empty
  if(root == NULL) {
       return false;
  }

  // crete pointers
  TreeNode<T> *curr = root;
  TreeNode<T> *parent = root;
  bool isLeft = true;

  // find key's location on tree and if it's on the left or right side of the tree
  while(curr->key != k) {
    parent = curr;

    if(k < curr->key) {
      isLeft = true;
      curr = curr->left;
    }
    else {
      isLeft = false;
      curr = curr->right;
    }

    if(curr == NULL) {
      return false;
    }
  }

  // Node has no children and can easily be deleted
  if(curr->left == NULL && curr->right == NULL) {
    if(curr == root) {
      root = NULL;
    }
    else if(isLeft) {
      parent->left = NULL;
    }
    else {
      parent->right = NULL;
    }
  }

  //Delete node with one child on the left side
  else if(curr->right == NULL) {
   if(curr == root) {
      root = curr->left;
    }
   else if(isLeft) {
      parent->left = curr->left;
    }
    else {
      parent->right = curr->right;
    }
  }

  //Delete node with one child on the right side
  else if(curr->left == NULL) {
    if(curr == root) {
        root = curr->right;
    }
    else if(isLeft) {
        parent->left = curr->right;
    }
    else {
        parent->right = curr->right;
    }
  }

  //Delete node with two children nodes
  else {
      TreeNode<T> *successor = getPreviousNode(curr); /////////

      if(curr == root) {
        root = successor;
      }

      else if(isLeft) {
        parent->left = successor;
      }
      else {
        parent->right = successor;
      }
      successor->left = curr->left;
  }
  --size;
  return true;
}

// print nodes in the tree beggening from a specific node
template <class T>
void BinarySearchTree<T>::printRecursively(TreeNode<T> *node) {
  if (node == NULL) {
    return;
  }

  // print on the left and the right of the node sent in
  printRecursively(node->left);
  printRecursively(node->right);
}

// print all nodes in the tree beggening from the root node
template <class T>
void BinarySearchTree<T>::printTree() {
  printRecursively(root);
}

// find the smallest node in the tree
template <class T>
T* BinarySearchTree<T>::getMin() {
  TreeNode<T> *curr = root;

  // check if tree is empty
  if (root == NULL) {
    return NULL;
  }

  // smallest variable will be left most node in the tree
  while (curr->left != NULL) {
    curr = curr->left;
  }

  return curr;
}

// find the largest node in the tree
template <class T>
T* BinarySearchTree<T>::getMax() {
  TreeNode<T> *curr = root;

  // check if tree is empty
  if (root == NULL) {
    return NULL;
  }

  // largest variabe will be the right most node
  while(curr->right != NULL) {
    curr = curr->right;
  }

  return curr;
}

// return the root of the tree
template <class T>
TreeNode<T>* BinarySearchTree<T>::getRoot() {
  return root;
}

// return the number of nodes or the size of the tree
template <class T>
int BinarySearchTree<T>::getSize() {
  return size;
}

// check if the tree contains no more nodes
template <class T>
bool BinarySearchTree<T>::isEmpty() {
  return(size == 0);
}
