
// Binary Search Tree Implementation file
// Maximilian Medearis

#include <iostream> 
#include <utility> 
#include <string>
#include <algorithm>
#include "bst.h"
using namespace std;

bool BST::searchWord(string word){
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

Node * BST::searchWord(string word, Node *n){
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

// Change to incorporate AVL Tree method
bool BST::insertWord(const string word){
    if (this->head == NULL){
        this->insertWord(word, head);
        return true;
    }
    Node *m = this->searchWord(word, head);
    
    // If word already exists
    if (m != NULL){
        m->word.second ++;
        cout << word << " inserted, new count = " << m->word.second << endl;
        return true;}

    return insertWord(word, head);
    

}

bool BST::insertWord(string word, Node * n){
    
    if (!this->head){
        head = new Node;
        this->head->word.first = word;
        this->head->word.second = 1;
        cout << word << " inserted, new count = " << 1 << endl;
        return true;
    }
    if (word < n->word.first){
        if (n->left == NULL){
            n->left = new Node;
            n->left->parent = n;
            n->left->word.first = word;
            n->left->word.second = 1;
            cout << word << " inserted, new count = " << 1 << endl;
            return true;
        }
        return insertWord(word, n->left);
    }
    else if (word > n->word.first){
        if (n->right == NULL){
            n->right = new Node;
            n->right->parent = n;
            n->right->word.first = word;
            n->right->word.second = 1;
            cout << word << " inserted, new count = " << 1 << endl;
            return true;
        }
        return insertWord(word, n->right);
    }
    else return 0;
}

bool BST::insertWordInitial(const string word){
    if (this->head == NULL){
        this->insertWordInitial(word, head);
        return true;
    }
    Node *m = this->searchWord(word, head);
    
    // If word already exists
    if (m != NULL){
        m->word.second ++;
        
        return true;}

    return insertWordInitial(word, head);
    

}

bool BST::insertWordInitial(string word, Node * n){
    
    if (!this->head){
        head = new Node;
        this->head->word.first = word;
        this->head->word.second = 1;
        
        return true;
    }
    if (word < n->word.first){
        if (n->left == NULL){
            n->left = new Node;
            n->left->parent = n;
            n->left->word.first = word;
            n->left->word.second = 1;
            
            return true;
        }
        return insertWordInitial(word, n->left);
    }
    else if (word > n->word.first){
        if (n->right == NULL){
            n->right = new Node;
            n->right->parent = n;
            n->right->word.first = word;
            n->right->word.second = 1;
            
            return true;
        }
        return insertWordInitial(word, n->right);
    }
    else return 0;
}

bool BST::deleteWord(string word){
    Node *m = this->searchWord(word, head);

    if (m==NULL){
        return false;
    }

    if (m->word.second > 1){
        m->word.second --;
        cout << word << " deleted, new count = " << m->word.second << endl;
        return true;
    }
    
    return this->deleteWord(word, m);
}


bool BST::deleteWord(string word, Node *m){
    //No Child Case
    if (m->left == NULL && m->right == NULL){
        if (m->parent->left == m){
            m->parent->left = NULL;
        }
        if (m->parent->right == m){
             m->parent->right = NULL;
        }

        delete m;
        cout << word << " deleted\n";
        return true;
    }
    // One Child Case
    else if(m->left== NULL){
        if (m->parent->left == m){
            m->parent->left = m->right;
            m->right->parent = m->parent;
            delete m;
            cout << word << " deleted\n";
            return true;}
        else if (m->parent->right == m){
            m->parent->right = m->right;
            m->right->parent = m->parent;
            delete m;
            cout << word << " deleted\n";
            return true;}   
    }
    else if(m->right==NULL){
        if (m->parent->left == m){
            m->parent->left = m->left;
            m->left->parent = m->parent;
            delete m;
            cout << word << " deleted\n";
            return true;}
        else if (m->parent->right == m){
            m->parent->right = m->left;
            m->left->parent = m->parent;
            delete m;
            cout << word << " deleted\n";
            return true;}
        
}
    // two child case
    else{
        Node * rep = this->getSuccessor(word, m);
        std::swap(m->word.first, rep->word.first);
        std::swap(m->word.second, rep->word.second);
        this->deleteWordHelper(rep->word.first, rep);
        cout << word << " deleted\n";
        return true;

    }

    return false;

}

void BST::deleteWordHelper(string word, Node *m){
     
    if (m->left == NULL && m->right == NULL){
        if (m->parent->left == m){
            m->parent->left = NULL;
        }
        if (m->parent->right == m){
             m->parent->right = NULL;
        }

        delete m;
    }
    // One Child Case
    else if(m->left== NULL){
        if (m->parent->left == m){
            m->parent->left = m->right;
            m->right->parent = m->parent;
            delete m;
        }
        else if (m->parent->right == m){
            m->parent->right = m->right;
            m->right->parent = m->parent;
            delete m;
        }   
    }
    else if(m->right==NULL){
        if (m->parent->left == m){
            m->parent->left = m->left;
            m->left->parent = m->parent;
        
            }
        else if (m->parent->right == m){
            m->parent->right = m->left;
            m->left->parent = m->parent;
            delete m;
            }
        
}
    // two child case
    else{
        Node * rep = this->getSuccessor(word, m->left);
        std::swap(m->word.first, rep->word.first);
        std::swap(m->word.second, rep->word.second);
        this->deleteWordHelper(rep->word.first, rep);
        
        
    }

}

Node * BST::getSuccessor(string word, Node *n){
    Node * max = n;
    if (max->right){
        max = max->right;
        while (max->left){
            max = max->left;
        }
        return max;
    }
    while ((max->parent) && (max->parent->right == max) && (max != this->head))
        max = max->parent;
    if (max == this->head)
        return NULL;
    return max->parent;
}


bool BST::rangeSearch(string param1, string param2){
    this->rangeSearch(param1, param2, this->head);
    return true;
}

void BST::rangeSearch(string param1, string param2, Node *n){
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

void BST::clear(Node *n){
    if (n){
        clear(n->left);
        clear(n->right);
        delete n;
    }

}






