/*
Jadon Olson
CS3505
A4: A Trie and Rule-of-Three
*/

#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include "Node.h"
#include <vector>

using std::ostream;
using std::string;
using std::vector;

/// @brief Lays out the foundation of the Trie class
class Trie {
  
Node root;

public:
  Trie();//Default Constructor

  ~Trie();//Destructor
  Trie (const Trie& other);//Copy Constructor
  Trie& operator=(Trie other);//Assignment operator

  //Member methods
  bool isWord(string wordToCheck);
  void addWord(string wordToAdd);
  vector<string> allWordsStartingWithPrefix(string prefix);
  
};

#endif