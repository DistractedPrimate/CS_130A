
#include <iostream> 
#include <utility> 
#include <string>
#include <vector>

class HashTable {
    
    public:
        // Constructor
        HashTable() {}
        // Destructor
        ~HashTable() {}

        /*Search a given word. Both the BST and hash table should be searched to find the word.
        The program should print out ”[word] found”, along with the count of the word, once
        for each data structure. If the word is not found the program should output ”[word] not
        found”, once for each data structure.*/
        void searchWord(std::string word);

        /*Insert a word. If the word is already present then its counter should be increased by one.
        The program should output ”[word] inserted, new count = [count]”, once for each data
        structure.*/
        void insertWord(const std::string word);

        /*Delete a word. If the word has a count greater than 1 then the count gets decreased by
        1 and the program should output ”[word] deleted, new count = [count]”. If the word
        has count 1, then it shoud be removed from the data structures and the program should
        output ”[word] deleted”.*/
        void deleteWord(std::string word);

        /*Do a range search. The program should print out all words alphabetically in between (an
        including) the two words provided in the range search that are in the data structures.
        The program should do this once for both data structures.*/
        void rangeSearch(std::string param1, std::string param2);

        void insertWordInitial(const std::string word);

    private:

        //structure
        std::vector<std::pair<std::string, int> > table[10000];
        
        //Hash Function
        size_t Hash(std::string word);







};