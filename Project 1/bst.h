
// Maximilian Medearis
// Binary Search Tree Header

#include <iostream> 
#include <utility> 
#include <string>

struct Node {
    Node () : left(0), right(0), parent(0) {}
    std::pair <std::string, int> word;
    Node * left; 
    Node * right;
    Node * parent;
    
    
    //Red Black Tree implementation details
    /*
    Node * parent;
    bool isRed;
    bool isSent;*/

};

class BST {
    public:
        // Constructor
        BST() {this->head = nullptr;}
        // Destructor
        ~BST() {clear(head);}

        /*Search a given word. Both the BST and hash table should be searched to find the word.
        The program should print out ”[word] found”, along with the count of the word, once
        for each data structure. If the word is not found the program should output ”[word] not
        found”, once for each data structure.*/
        bool searchWord(std::string word);

        /*Insert a word. If the word is already present then its counter should be increased by one.
        The program should output ”[word] inserted, new count = [count]”, once for each data
        structure.*/
        bool insertWord(const std::string word);

        /*Delete a word. If the word has a count greater than 1 then the count gets decreased by
        1 and the program should output ”[word] deleted, new count = [count]”. If the word
        has count 1, then it shoud be removed from the data structures and the program should
        output ”[word] deleted”.*/
        bool deleteWord(std::string word);

        /*Do a range search. The program should print out all words alphabetically in between (an
        including) the two words provided in the range search that are in the data structures.
        The program should do this once for both data structures.*/
        bool rangeSearch(std::string param1, std::string param2);

        bool insertWordInitial(const std::string word);

    private:
        
        Node *head;

        //Helper Methods
        Node * searchWord(std::string word, Node *n);
        Node * getSuccessor(std::string word, Node *n);
        bool insertWord(std::string word, Node *n);
        bool insertWordInitial(std::string word, Node *n);
        bool deleteWord(std::string word, Node *m);
        void deleteWordHelper(std::string word, Node *m);
        void clear(Node *n);
        void rangeSearch(std::string param1, std::string param2, Node * n);
};
