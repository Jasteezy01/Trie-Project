/*
Jadon Olson
CS3505
A4: A Trie and Rule-of-Three
*/

#ifndef NODE_H
#define NODE_H
#include <algorithm>

/// @brief Lays out the foundation of the Node class
class Node {
public:
    bool isWord;
    Node** branches;
    Node();
    ~Node();
    Node(const Node& other);
    Node& operator=(Node other);
};

#endif