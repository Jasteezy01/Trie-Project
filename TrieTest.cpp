/*
Jadon Olson
CS3505
A4: A Trie and Rule-of-Three
*/

#include <gtest/gtest.h>
#include "Trie.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/// @brief Load words from a file
/// @param filename the name of the file
/// @return all words in a file
vector<string> loadWordsFromFile(const string& filename) {
    vector<string> words;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return words;
    }
    
    string word;
    while (getline(file, word)) {
        words.push_back(word);
    }
    
    return words;
}

// Test the Trie using files specified directly in the test (replace with your actual file paths)
TEST(TrieTest, FileInputTest) {
    const string filenameWords = "words.txt";   // Replace with actual filename
    const string filenameQueries = "queries.txt"; // Replace with actual filename

    Trie testTrie;

    // Load words from the first file and insert into Trie
    vector<string> words = loadWordsFromFile(filenameWords);
    ASSERT_FALSE(words.empty()) << "Word file is empty or could not be loaded!";
    
    for (const string& word : words) {
        testTrie.addWord(word);
    }

    // Load queries from the second file and test Trie
    vector<string> queries = loadWordsFromFile(filenameQueries);
    ASSERT_FALSE(queries.empty()) << "Query file is empty or could not be loaded!";

    for (const string& query : queries) {
        cout << "Checking text: " << query << endl;
        if (testTrie.isWord(query)) {
            cout << "Word found" << endl;
        } else {
            cout << "Word not found" << endl;
        }

        // Get and output words that start with the query prefix
        vector<string> wordsWithPrefix = testTrie.allWordsStartingWithPrefix(query);
        for (const string& word : wordsWithPrefix) {
            cout << word << " ";
        }
        cout << endl;
    }
}

// Test copy constructor, assignment operator, and independence of Trie objects (Rule-of-Three)
TEST(TrieTest, RuleOfThreeTest) {
    Trie firstTrie;
    firstTrie.addWord("cat");
    firstTrie.addWord("dog");
    
    // Test copy constructor
    Trie copiedTrie(firstTrie);  // Create a copy using the copy constructor
    EXPECT_EQ(1, copiedTrie.isWord("cat"));
    EXPECT_EQ(1, copiedTrie.isWord("dog"));
    
    // Modify the original Trie and check that the copied Trie is independent
    firstTrie.addWord("bird");
    EXPECT_FALSE(copiedTrie.isWord("bird"));  // "bird" should not be in the copied Trie
    
    // Test assignment operator
    Trie assignedTrie;
    assignedTrie = firstTrie;  // Test assignment
    EXPECT_EQ(1, assignedTrie.isWord("cat"));
    EXPECT_EQ(1, assignedTrie.isWord("dog"));
    EXPECT_EQ(1, assignedTrie.isWord("bird"));

    // Modify the original Trie and check that the assigned Trie is independent
    firstTrie.addWord("fish");
    EXPECT_FALSE(assignedTrie.isWord("fish"));  // "fish" should not be in the assigned Trie
}

/// @brief Main funciton just runs all the tests
/// @param argc 
/// @param argv 
/// @return 
int main(int argc, char** argv) {
    RUN_ALL_TESTS();
    return 0;
}
