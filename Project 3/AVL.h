

#include <iostream> 
#include <utility> 
#include <string>


struct Node {
            Node () : left(0), right(0), parent(0) {}
            std::pair <std::string, int> word;
            Node * left; 
            Node * right;
            Node * parent;
            bool isRightChild();
        };


class AVL {
    /*struct Node {
        Node () : left(0), right(0), parent(0), height(0) {}
        std::pair <std::string, int> word;
        Node * left; 
        Node * right;
        Node * parent;
        bool isRightChild();
    };*/
    
    public:

        
        
        // Constructor (Same as BST)
        AVL() {this->head = nullptr;}
        
        // Destructor (Same as BST)
        ~AVL() {clear(head);}

        /*Search a given word. Both the AVL and Two Five should be searched to find the word.
        The program should print out ”[word] found”, along with the count of the word, once
        for each data structure. If the word is not found the program should output ”[word] not
        found”, once for each data structure.*/
        bool searchWord(const std::string word);

        /*Insert a word. If the word is already present then its counter should be increased by one.
        The program should output ”[word] inserted, new count = [count]”, once for each data
        structure. We must restore the Properties of the AVL Tree. We must adjust the height of the nodes
        along the way */
        void insertWord(const std::string word);

        /*Do a range search. The program should print out all words alphabetically in between (an
        including) the two words provided in the range search that are in the data structures.
        The program should do this once for both data structures.*/
        bool rangeSearch(std::string param1, std::string param2);
        

        /*Print out a traversal of the tree. The program should print out the values of the tree
        using a pre-order traversal. For each node, you must do the following: print an open
        parenthesis, the node’s data, print the nodes’ children from left to right, followed by a
        close-parenthesis.
        For each datum, you must print the key and value separated by a colon. If a node has
        multiple data elements, you should delimit them using commas. For any children that
        are null, you should print empty parentheses.
        Ex:
        An AVL tree with root value (hello, 3) and children (ahoy, 4) and (howdy, 1) should be
        printed as follows:
        (hello:3(ahoy:4()())(howdy:1()()))*/
        void printTraversal();

        void insertWordInitial(const std::string word);

        void getHeight() {std::cout << "Height " << this->getHeight(this->head);}

    private:
        
        Node *head;

        //Helper Methods
        Node * searchWord(std::string word, Node *n);
        void insertWord(const std::string word, Node *n);
        void rotateRight(Node *x, Node *y);
        void rotateLeft(Node *x, Node *y);
        void doubleRotateRight(Node *x, Node *y);
        void doubleRotateLeft(Node *x, Node *y);
        void FixImbalance(Node *n, bool childisRight, bool grandchildisRight);
        int getHeight(Node *n);
        int getHeight(Node *n, int height);
        void printTraversal(Node *n);
        void clear(Node *n);
        void rangeSearch(std::string param1, std::string param2, Node *n);
        
};