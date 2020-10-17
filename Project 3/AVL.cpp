
#include <iostream> 
#include <utility> 
#include <string>
#include <cmath>
#include "AVL.h"
using namespace std;


// These Methods should be identical to those present in a Binary Search Tree

bool AVL::searchWord(string word){
    if (head == NULL){
        cout << word << " not found\n";
        return false;
    }
    Node * m = this->searchWord(word, this->head);
    if (m == NULL){
        cout << word << " not found" << endl;
        return false;}

    cout << word << " found, count = " << m->word.second << endl;
    return true;    

}

Node * AVL::searchWord(string word, Node *n){
    if (n == NULL){
        return NULL;}
    if (word == n->word.first){
        return n;
    }
    else if (word > n->word.first){
        return this->searchWord(word, n->right);
    }
    else if (word < n->word.first){
        return this->searchWord(word, n->left);
    }
    return NULL;
}


bool AVL::rangeSearch(string param1, string param2){
    this->rangeSearch(param1, param2, this->head);
    return true;
}

void AVL::rangeSearch(string param1, string param2, Node *n){
    if (n==NULL){
        return;
    }
    if (n->word.first > param1){
        this->rangeSearch(param1, param2, n->left);
    }
    if (n->word.first >= param1 && n->word.first <= param2){
        cout << n->word.first << endl;
    }
    if (n->word.first < param2){
        this->rangeSearch(param1, param2, n->right);
    }
}

void AVL::insertWord(const string word){
    if (this->head == NULL){
        this->insertWord(word, head);
        return;
    }
    
    //cout << "before search\n";
    Node *m = searchWord(word, head);
    //cout << "after search\n";
    if (m != NULL){
        //cout << "second inserton\n";
        m->word.second ++;
        cout << word << " inserted, new count = " << m->word.second << endl;
        return;}

    cout << word << " inserted, new count = " << 1 << endl;
    //cout << "after string\n";
    insertWord(word, head);
    return;

}

void AVL::insertWord(const string word, Node *n){
    if (!this->head){
        head = new Node;
        this->head->word.first = word;
        this->head->word.second = 1;
        return;
    }
    
    if (word < n->word.first){
        if (n->left == NULL){
            n->left = new Node;
            n->left->parent = n;
            n->left->word.first = word;
            n->left->word.second = 1;
            
            // Check for imbalances
            FixImbalance(n, false, false);
            //cout << word << " inserted, new count = " << 1 << endl;
            return;
        }
        return insertWord(word, n->left);
    }
    else if (word > n->word.first){
        if (n->right == NULL){
            n->right = new Node;
            n->right->parent = n;
            n->right->word.first = word;
            n->right->word.second = 1;
            
            // Check for imbalances
            FixImbalance(n, true, true);
            //cout << word << " inserted, new count = " << 1 << endl;
            return;
        }
        return insertWord(word, n->right);
    }
    else return;
}

void AVL::insertWordInitial(string word){
    if (!this->head){
        head = new Node;
        head->word.first = word;
        head->word.second = 1;
        //cout << head->word.first << endl;
        //cout << "first insertion\n";
        return;
    }
    //cout << "before search\n";
    Node *m = searchWord(word, head);
    //cout << "after search\n";
    if (m != NULL){
        //cout << "second inserton\n";
        m->word.second ++;
        //cout << word << " inserted, new count = " << m->word.second << endl;
        return;}

    //cout << word << " inserted, new count = " << 1 << endl;
    //cout << "after string\n";
    insertWord(word, head);
    return;


}

void AVL::FixImbalance(Node *n, bool childisRight, bool grandchildisRight){
    
    if (!n){
        return;
    }
    
    // negative value, right tree is bigger than left, positive left is bigger than right
    //cout << "here\n";
    int difference = getHeight(n->left) - getHeight(n->right);
    //cout << "here after\n";
    if (abs(difference) < 3){
        FixImbalance(n->parent, n->isRightChild(), childisRight);
        //cout << "here after recursive\n";
        return;
    }


    if (difference < 0){
    // Right Right exterior Node
        if (childisRight == true && grandchildisRight==true){
            rotateLeft(n, n->right);
        }

        // Right Rotate interior Node
        else if (childisRight == true && grandchildisRight==false){
            doubleRotateRight(n, n->right);
        }
    }

    if (difference > 0){
    // Left Rotate exterior Node
        if (childisRight == false && grandchildisRight==false){
            rotateRight(n, n->right);
        }
        
        // Left Rotate interior Node
        else if (childisRight == false && grandchildisRight==true){
            doubleRotateLeft(n, n->right);
        }
    }
    

}

void AVL::rotateLeft(Node *x, Node *y){
    // x becomes y's left child, y's left child becomes x's right child
    x->right = y->left;
    x->right->parent = x;
    
    //if x is right child, y is x's parent's right child else opposite
    if(x->isRightChild()){
        x->parent->right = y;
    }
    else{
        x->parent->left = y;
    }
    y->parent = x->parent;
    y->left = x;
    x->parent = y;
    if (head==x){
        head=y;
    }
}

void AVL::rotateRight(Node *x, Node *y){
    // x becomes y's right child becomes, y's right child becomes x's left child
    x->left = y->right;
    x->left->parent = x;
    
    //if x is right child, y is x's parent's right child else opposite
    if(x->isRightChild()){
        x->parent->right = y;
    }
    else{
        x->parent->left = y;
    }
    y->parent = x->parent;
    y->right = x;
    x->parent = y;
    if (head==x){
        head=y;
    }

}


void AVL::doubleRotateLeft(Node *x, Node *y){
    rotateLeft(y, y->right);
    rotateRight(x, x->left);
}


void AVL::doubleRotateRight(Node *x, Node *y){
    rotateRight(y, y->right);
    rotateLeft(x, x->left);
}

int AVL::getHeight(Node *n){
    if (!n){
        return -1;
    }
    return getHeight(n, 0);
}

int AVL::getHeight(Node *n, int height){
    if (n == NULL){
        return -1;
    }
    if (n->left == 0 && n->right == 0){
        return 0;
    }
    else return max(getHeight(n->left, height+1), getHeight(n->right,height+1));
}


bool Node::isRightChild(){
    if (!this->parent){
        return false;
    }
    if (this->parent->right == this){
        return true;
    }
    return false;
}

void AVL::printTraversal(){
    printTraversal(head);
    cout << "\n";
}

void AVL::printTraversal(Node *n){
    if (!n){
        cout << "()";
        return;
    }

    cout << "(" << n->word.first << ":" << n->word.second;
    printTraversal(n->left);
    printTraversal(n->right);
    cout << ")";
    return;
}


void AVL::clear(Node *n){
    if (n==NULL){
        return;
    }
    if (n){
        //cout << n->word.first << endl;
        clear(n->left);
        clear(n->right);
        delete n;
    }

}