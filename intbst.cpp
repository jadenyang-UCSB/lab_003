// intbst.cpp
// Implements class IntBST
//Jaden Yang

#include "intbst.h"

#include <iostream>
#include <vector>
using namespace std;
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
    root = nullptr;
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if(n == nullptr){
        return;
    }
    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    bool A = insert(value, root); // REPLACE THIS NON-SOLUTION
    return A;
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if(n == nullptr){
        root = new Node;
        root->info = value;

        root->parent = nullptr;
        root->left = nullptr;
        root->right = nullptr;

        return true;
    }

    if(n->info == value){
        return false;
    }

    else if(n->info > value){
        if(n->left == nullptr){
            n->left = new Node;
            n->left->parent = n;
            n->left->info = value;
            n->left->left = nullptr;
            n->left->right = nullptr;

            return true;
        }
        else{
            insert(value,n->left);
        }
    }

    else{
        if(n->right == nullptr){
            n->right = new Node;
            n->right->parent = n;
            n->right->info = value;
            n->right->right = nullptr;
            n->right->left = nullptr;
            return true;
        }
        else{
            insert(value,n->right);
        }
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    // cout << "IMPLEMENT printPreOrder public method";; // IMPLEMENT HERE
    printPreOrder(root);
    return;
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    // cout << "IMPLEMENT printPreOrder private helper method"; // IMPLEMENT HERE
    if(n == nullptr){
        return;
    }
    cout << n->info << " ";
    printPreOrder(n->left);
    printPreOrder(n->right);
    return;
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    // cout << "IMPLEMENT printInOrder public method"; // IMPLEMENT HERE
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    // cout << "IMPLEMENT IMPLEMENT printInOrder private helper method"; // IMPLEMENT HERE
    if(n == nullptr){
        return;
    }
    printInOrder(n->left);
    cout << n->info << " ";
    printInOrder(n->right);
    return;
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    // cout << "IMPLEMENT printPostOrder public method"; // IMPLEMENT HERE
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    // cout << "IMPLEMENT printPostOrder private helper method";// IMPLEMENT HERE
    if(n == nullptr){
        return;
    }
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info << " ";
    return;
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if(n == nullptr){
        return 0;
    }
    int x = sum(n->left);
    int y = sum(n->right);
    return x + y + n->info;
    return -1; // REPLACE THIS NON-SOLUTION
}

// return count of values
int IntBST::count() const {
    return count(root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if(n == nullptr){
        return 0;
    }
    int x = count(n->left);
    int y = count(n->right);
    return x + y + 1;
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if(n == nullptr){
        return nullptr;
    }
    if(value == n->info){
        return n;
    }
    else{
        if(n->info > value){
            return getNodeFor(value,n->left);
        }
        else{
            return getNodeFor(value,n->right);
        }
    }
    return nullptr; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    if(getNodeFor(value,root) != nullptr){
        return true;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{ 
    int x = getPredecessor(value); // REPLACE THIS NON-SOLUTION
    return getNodeFor(x,root);
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node* called = getNodeFor(value, root);

    if(!called){
        return 0;
    }

    Node* parentNode = called->parent;
    Node* iterator = called;

    while(parentNode && parentNode->info > value){
        if(!(parentNode->parent)){
            return 0;
        }
        parentNode = parentNode->parent;
    }


    if(!(iterator->left)){
        return parentNode->info;
    }

    iterator = iterator->left;

    while(iterator -> right){
        iterator = iterator->right;
    }

    return iterator->info;
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    int x = getSuccessor(value); // REPLACE THIS NON-SOLUTION
    return getNodeFor(x,root);
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node* iterator = getNodeFor(value,root);
    if(!iterator){
        return 0;
    }
    
    Node* parentNode = iterator->parent;

    // if(!(iterator->right)){
    //     return parentNode->info;
    // }
    if(iterator->right){
        iterator = iterator->right;

        while(iterator->left){
            iterator = iterator->left;
        }
    }
    else{
        while((parentNode) && (parentNode->info < iterator->info)){
            if(!(parentNode->parent)){
                return 0;
            }
            parentNode = parentNode->parent;
        }
        return parentNode->info;
    }

    return iterator->info;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist

bool IntBST::changer(Node* a, Node* b){
    Node* LEFT = b->left;
    Node* RIGHT = b->right;

    if(LEFT && RIGHT){
        Node* success = getSuccessorNode(b->info);
        Node* successParent = success->parent;
        b->info = success->info;
        return changer(successParent,success);
    }

    else if(!LEFT && !RIGHT){

        if(b == root){
            root = nullptr;
            delete b;
            return true;
        }

        if(a->left == b){
            a->left = nullptr;
            delete b;
        }
        else{
            a->right = nullptr;
            delete b;
        }
        return true;
    }

    else{
        if(!RIGHT && LEFT){

            if(b == root){
                root = root->left;
                root->parent = nullptr;
                delete b;
                return true;
            }

            if(a->right == b){
                a->right = LEFT;
            }
            else{
                a->left = LEFT;
            }
            LEFT->parent = a;
            delete b;
        }
        else{

            if(b == root){
                root = root->right;
                root->parent = nullptr;
                delete b;
                return true;
            }

            if(a->right == b){
                a->right = RIGHT;
            }
            else{
                a->left = RIGHT;
            }
            RIGHT->parent = a;
            delete b;
        }
        return true;
    }
    return true;
}

bool IntBST::remove(int value){

    if(!getNodeFor(value,root)){
        return false;
    }

    return changer(getNodeFor(value,root)->parent,getNodeFor(value,root));
}
