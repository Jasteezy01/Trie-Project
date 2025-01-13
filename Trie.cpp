/*
Jadon Olson
CS3505
A4: A Trie and Rule-of-Three
*/

#include "Trie.h"

/// @brief Trie constructor
Trie::Trie(): root(){
}

/// @brief Trie destructor
Trie::~Trie(){
}

/// @brief Trie copy constructor
/// @param other other trie we are copying from
Trie::Trie (const Trie& other): root(other.root){}

/// @brief Assignment operator
/// @param other trie we are swapping with
/// @return updated trie
Trie& Trie::operator=(Trie other){
    std::swap(root, other.root);  // Swap roots
    return *this;
}

/// @brief Add word to current trie
/// @param wordToAdd word we are adding
void Trie::addWord(string wordToAdd){
    Node* currentNode = &root;  // Start from the root node
    for (int charIndex = 0; charIndex < wordToAdd.length(); charIndex++) {
        char currentChar = wordToAdd[charIndex];
        int branchIndex = currentChar - 'a';  // Calculate the index for 'a' to 'z' (0 to 25)

        // If the branch doesn't exist, create a new node
        if (currentNode->branches[branchIndex] == nullptr) {
            currentNode->branches[branchIndex] = new Node();
        }
        currentNode = currentNode->branches[branchIndex];  // Move to the next node
    }

    // After the loop, mark the last node as the end of a valid word
    currentNode->isWord = true;
}

/// @brief Check to see if word has been added to tree 
/// @param wordToCheck The word we are checking for
/// @return true if word exists, false if it doesn't
bool Trie::isWord(string wordToCheck){
     // Start from the root node
    Node* currentNode = &root;
    
    // Traverse the Trie using the characters of the word
    for (int charIndex = 0; charIndex < wordToCheck.length(); charIndex++) {
        char currentChar = wordToCheck[charIndex];
        
        // Ensure the character is a valid lowercase letter between 'a' and 'z'
        if (currentChar < 'a' || currentChar > 'z') {
            return false;  // Invalid character, return false
        }
        
        int branchIndex = currentChar - 'a';  // Calculate the index for 'a' to 'z' (0 to 25)
        
        // Check if the branch for the current character exists
        if (currentNode->branches[branchIndex] == nullptr) {
            return false;  // Word is not in the Trie
        }

        // Move to the next node in the Trie
        currentNode = currentNode->branches[branchIndex];
    }
    
    // After traversing the entire word, check if the last node marks the end of a valid word
    return currentNode->isWord;
}

/// @brief Helper method for allWordsStartingWithPrefix
/// @param node Node we are starting at
/// @param currentPrefix the current prefix we are looking at
/// @param result the vector that will be returned
void findAllWordsFromNode(Node* node, std::string currentPrefix, std::vector<std::string>& result) {
    // If the current node marks the end of a word, add it to the result
    if (node->isWord) {
        result.push_back(currentPrefix);
    }

    // Recursively explore all children nodes
    for (int i = 0; i < 26; ++i) {
        if (node->branches[i] != nullptr) {
            // Convert index back to a character ('a' + i) and append it to the current prefix
            char nextChar = 'a' + i;
            findAllWordsFromNode(node->branches[i], currentPrefix + nextChar, result);//Recursively call the next char
        }
    }
}

/// @brief Find all words that start with a given prefix
/// @param prefix the given prevfix
/// @return all strings in the trie that started with that prefix
vector<string> Trie::allWordsStartingWithPrefix(string prefix){
    std::vector<std::string> result;  // To store all the words that match the prefix
    Node* currentNode = &root;

    // Traverse the Trie based on the prefix
    for (int charIndex = 0; charIndex < prefix.length(); charIndex++) {
        char currentChar = prefix[charIndex];
        
        // Ensure the character is a valid lowercase letter between 'a' and 'z'
        if (currentChar < 'a' || currentChar > 'z') {
            return result;  // Invalid character, return an empty result
        }

        int branchIndex = currentChar - 'a';

        // Check if the branch for the current character exists
        if (currentNode->branches[branchIndex] == nullptr) {
            return result;  // Prefix not in the Trie, return an empty result
        }

        currentNode = currentNode->branches[branchIndex];  // Move to the next node
    }

    // We are now at the node corresponding to the last character of the prefix
    // Now we need to find all words from this point onward
    findAllWordsFromNode(currentNode, prefix, result);

    return result;
}



