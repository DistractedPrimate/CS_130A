
#include <iostream> 
#include <utility> 
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "25Tree.h"
using namespace std;

bool myfunction (TNode * i, TNode * j) { return (i->words[0]<j->words[0]); }

TNode::TNode(){
    this->isLeaf = true;
    this->parent = NULL;
}

void TwoThree::insert(string word){

    // If there is a new tree
    if (root == NULL){
        root = new TNode;
        //root->insert(word, this);
        cout << "here\n";
        height = 0;
        insert(word, root);
        
    }

    // else insert on root, begin recursive path
    //root->insert(word, this);
    insert(word, root);
}

void TwoThree::search(string word){

    // If there is a new tree
    if (root == NULL){
        return;
    }

    search(word, root);

}

void TwoThree::search(string word, TNode * n){
    int placeInVector = 0;
    for (size_t loc=0; loc < n->words.size(); loc++){
        if (word == n->words[loc].first){
            cout << word << " found, count = " << n->words[loc].second << endl;
            return;
        }
        if (word > n->words[loc].first){
            placeInVector ++;
        }
    }
    if (!n->isLeaf){
        search(word, n->childs[placeInVector]);
        //this->childs[placeInVector]->insert(word)
    }

    else{
        
        cout << word << " not found" << endl;
        return;
        // not found
    }

}


/*void TNode::insert(string word, TwoThree A){
    // Check if duplicate of word is already in root
    int placeInVector = 0;
    sort(childs.begin(), childs.end(), myfunction);
    for (size_t loc=0; loc < this->words.size(); loc++){
        if (word == words[loc].first){
            words[loc].second ++;
            cout << word << " inserted, new count = " << words[loc].second << endl;
            return;
        }
        if (word > words[loc].first){
            placeInVector ++;
        }
    }

    // if leaf
    pair <string,int> wordPair (word, 1);
    if (isLeaf){
        
        // message about insertion
        words.push_back(wordPair);
        sort(words.begin(), words.end());
        cout << word << " inserted, new count = " << 1 << endl;
        if (words.size() > 5){
            this->split(word, A);
            return;
        }
    }

    // If not leaf
    else this->childs[placeInVector]->insert(word, root);
    
}*/

void TwoThree::insert(string word, TNode * n){
    // Check if duplicate of word is already in root
    int placeInVector = 0;
    sort(n->childs.begin(), n->childs.end(), myfunction);
    for (size_t loc=0; loc < n->words.size(); loc++){
        if (word == n->words[loc].first){
            n->words[loc].second ++;
            cout << word << " inserted, new count = " << n->words[loc].second << endl;
            return;
        }
        if (word > n->words[loc].first){
            placeInVector ++;
        }
    }

    // if leaf
    pair <string,int> wordPair (word, 1);
    if (n->isLeaf){
        
        // message about insertion
        n->words.push_back(wordPair);
        sort(n->words.begin(), n->words.end());
        cout << word << " inserted, new count = " << 1 << endl;
        if (n->words.size() > 5){
            split(word, n);
            return;
        }
        return;
    }

    // If not leaf
    insert(word, n->childs[placeInVector]);
    
}


/*void TNode::split(string word, TwoThree A){
    sort(childs.begin(), childs.end(), myfunction);
    sort(words.begin(), words.end());
    TNode * left = new TNode;
    TNode * right = new TNode;
    //Node * parent = new Node;
    pair<string, int> mid;
    
    if (parent == NULL){
        parent = new TNode;
        parent->isLeaf = false;
        A.changeRoot(this->parent);
    }

    for (size_t loc = 0; loc < words.size(); loc++){
        cout << "inserting into parent... " << loc << endl;
        if (loc < words.size()/2){
            left->words.push_back(words[loc]);
        }
        else if (loc > words.size()/2 + 1){
            right->words.push_back(words[loc]);
        }
        else mid = words[loc];
    }

    if (!isLeaf){
        for (size_t loc = 0; loc < childs.size(); loc++){
            if (loc < words.size()/2){
                left->childs.push_back(childs[loc]);
            }
            else if (loc > words.size()/2){
                right->childs.push_back(childs[loc]);
            }
        }
        
    }

    cout << "finalization... " << endl;
    this->parent->words.push_back(mid);
    this->parent->childs.push_back(left);
    this->parent->childs.push_back(right);
    cout << "finalization... " << endl;
    this->parent->childs.erase(std::remove(this->parent->childs.begin(), this->parent->childs.end(), this), this->parent->childs.end());
    cout << "finalization... " << endl;
    sort(this->parent->childs.begin(), this->parent->childs.end(), myfunction);
    sort(this->parent->words.begin(), this->parent->words.end());
    //delete this;
    


}*/

void TwoThree::split(string word, TNode * n){
    sort(n->childs.begin(), n->childs.end(), myfunction);
    sort(n->words.begin(), n->words.end());
    TNode * left = new TNode;
    TNode * right = new TNode;
    //Node * parent = new Node;
    pair<string, int> mid;
    
    if (n->parent == NULL){
        n->parent = new TNode;
        n->parent->isLeaf = false;
        root = n->parent;
        height ++;
    }

    left->parent = n->parent;
    right->parent = n->parent;

    for (size_t loc = 0; loc < n->words.size(); loc++){
        //cout << "inserting into parent... " << loc << endl;
        if (loc < n->words.size()/2){
            left->words.push_back(n->words[loc]);
        }
        else if (loc > n->words.size()/2){
            right->words.push_back(n->words[loc]);
        }
        else mid = n->words[loc];
    }

    if (!n->isLeaf){
        left->isLeaf = false;
        right->isLeaf = false;
        for (size_t loc = 0; loc < n->childs.size(); loc++){
            if (loc < n->words.size()/2){
                left->childs.push_back(n->childs[loc]);
            }
            else if (loc > n->words.size()/2){
                right->childs.push_back(n->childs[loc]);
            }
        }
        
    }

    //cout << "finalization... " << endl;
    n->parent->words.push_back(mid);
    n->parent->childs.push_back(left);
    n->parent->childs.push_back(right);
    /*for (auto i : n->parent->childs){
        cout << i << endl;
    }*/
    //cout << "finalization... " << endl;
    n->parent->childs.erase(std::remove(n->parent->childs.begin(), n->parent->childs.end(), n), n->parent->childs.end());
    //cout << "finalization... " << endl;
    sort(n->parent->words.begin(), n->parent->words.end());
    //cout << "finalization... " << endl;
    sort(n->parent->childs.begin(), n->parent->childs.end(), myfunction);
    delete n;
    //cout << "finalization... " << endl;
    /*for (auto i : n->parent->words){
        cout << i.first << i.second << endl;
    }

    //cout << "root\n";

    for (auto a : root->words){
        cout << a.first << a.second << endl;
    }

    int a = 0;
    for (auto j : n->parent->childs){
        cout << a << endl;
        for (auto k : j->words){
            cout << k.first << " " << k.second << endl;
        }
        a++;
    }*/

}


void TwoThree::rangeSearch(std::string lower,  std::string upper){
    rangeSearch(lower, upper, root);
    /*cout << root->isLeaf << endl;
    for (auto u : root->words){
        cout << u.first << " ";
    }
    cout << endl;*/
}

void TwoThree::rangeSearch(string lower,  string upper, TNode * n){
    /*cout << n->isLeaf << endl;
    for (auto u : n->words){
        cout << u.first << " ";
    }
    cout << endl;*/
    if (!n->isLeaf){
        for (size_t loc = 0; loc < n->words.size(); loc++){
            rangeSearch(lower, upper, n->childs[loc]);
            if(n->words[loc].first >= lower && n->words[loc].first <= upper){
                cout << n->words[loc].first << endl;
            }
        }
    }
    else{
        for (size_t loc = 0; loc < n->words.size(); loc++){
            if(n->words[loc].first >= lower && n->words[loc].first <= upper){
                //cout << "true" << endl;
                cout << n->words[loc].first << endl;
            }
        }
    }
    return;
}

/*void TwoThree::changeRoot(TNode * n){
    this->root = n;
    return;
}*/