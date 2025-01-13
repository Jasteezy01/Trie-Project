/*
Jadon Olson
CS3505
A4: A Trie and Rule-of-Three
*/

#include "Node.h"


/// @brief Node constructor
Node::Node(){
    isWord = false;
    branches = new Node*[26];  // Initialize branches to an array of 26 pointers
    for (int i = 0; i < 26; ++i) {
        branches[i] = nullptr;  // Initialize each branch to null
    }
}

/// @brief Node destructor
Node::~Node(){
    for (int i = 0; i < 26; ++i) {
        delete branches[i];  // Delete each Node 
    }
    delete[] branches;  // Delete the array of Node pointers
}

/// @brief Node copy constructor
/// @param other node with data that will be put into this
Node::Node(const Node& other){
    isWord = other.isWord;
    branches = new Node*[26];
    for (int i = 0; i < 26; ++i) { //Go through all branches and assign them the "other" value
        if (other.branches[i] != nullptr) {
            branches[i] = new Node(*other.branches[i]); 
        } else {
            branches[i] = nullptr;
        }
    }
}

/// @brief Assignment operator override
/// @param other other node we are swapping from
/// @return updated node
Node& Node::operator=(Node other){
    //Swap isWord and branches
    std::swap(isWord, other.isWord);
    std::swap(branches, other.branches);
    return *this;
}