
#include <iostream> 
#include <utility> 
#include <string>
#include <vector>
#include <set>
#include <map>


class TNode {
    public:
        TNode();
        //int location(std::string word);
        //void insert(std::string word, TwoThree A);
        //void split(std::string word, TwoThree A);
    private:
        std::vector<std::pair<std::string, int>> words;
        //Node * parent, leftmost, left, middle, right, rightmost;
        std::vector<TNode *> childs;
        bool isLeaf;
        int children;
        TNode * parent;
    

    friend class TwoThree;
    friend bool myfunction(TNode * i, TNode * j);
};

class TwoThree {

    public:
        TwoThree() {this->root = nullptr;}

        /*Search a given word. Both the AVL tree and the 2-5 tree should be searched to find the
        word. The program should print out ”[word] found”, along with the count of the word,
        once for each data structure. If the word is not found the program should output ”[word]
        not found”, once for each data structure.*/
        void search(std::string word);
        
        /*Insert a word. If the word is already present then its counter should be increased by one.
        The program should output ”[word] inserted, new count = [count]”, once for each data
        structure.*/
        void insert(std::string word);

        /*Do a range search. The program should print out all words alphabetically in between (an
        including) the two words provided in the range search that are in the data structures.
        Note that the two words given to perform the range search may or may not be in your
        data structures. The program should do this once for both data structures.*/
        void rangeSearch(std::string lower,  std::string upper);

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
        (hello:3(ahoy:4()())(howdy:1()()))
        A 2-5 tree node with values (cromulent, 2) and (embiggen, 4) should be printed as follows:
        (cromulent:2,embiggen:2()()())*/
        void preOrder();

        //Print the height of the tree. The code should simply output: ”Height = [height of tree]
        void getHeight() {std::cout << "Height = " <<  this->height;}

        //void TwoThree::changeRoot(TNode * n);

    private:
        TNode * root;
        void search(std::string word, TNode * n);
        void rangeSearch(std::string lower,  std::string upper, TNode * n);

        // Change these to memeber functions of TNode
        void insert(std::string word, TNode * n);
        void split(std::string word, TNode * n);
        int height;



};

