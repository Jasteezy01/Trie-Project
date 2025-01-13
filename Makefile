# Compiler and flags
CC = g++
FLAGS = -Wall -g -fsanitize=address -Igoogletest/googletest/include -Lgoogletest/lib -lgtest -lgtest_main

# Source files and object files
SRCS = Trie.cpp Node.cpp TrieTest.cpp
OBJS = Trie.o Node.o TrieTest.o
HEADERS = Trie.h Node.h

# Target executable
TARGET = TrieTest

# Default rule to build the executable
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJS)

# Compile the .cpp files into .o object files
Trie.o: Trie.cpp Trie.h Node.h
	$(CC) $(FLAGS) -c Trie.cpp

Node.o: Node.cpp Node.h
	$(CC) $(FLAGS) -c Node.cpp

TrieTest.o: TrieTest.cpp Trie.h Node.h
	$(CC) $(FLAGS) -c TrieTest.cpp

# Run tests (assumes words.txt and queries.txt are present in the current directory)
test: $(TARGET)
	./$(TARGET) words.txt queries.txt

# Clean up the build by removing object files and the executable
clean:
	rm -f $(TARGET) *.o
