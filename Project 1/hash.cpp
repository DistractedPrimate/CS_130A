
#include <iostream> 
#include <utility> 
#include <string>
#include <vector>
#include <algorithm>
#include "hash.h"
using namespace std;

size_t HashTable::Hash(string word){
   int key = 0;
   for (size_t i = 0; i < word.size(); i++){
       key += int(word[i]);
    }

    return key % 10000;
}


void HashTable::insertWord(const string word){
    int key = this->Hash(word);
    std::pair<string, int> a (word, 1);
    if (this->table[key].empty()){
        this->table[key].push_back(a);
        cout << this->table[key][0].first << " inserted, new count = " << a.second << endl;
        return;
    }

    else{
        for(size_t i = 0; i < table[key].size(); i++){
            if (this->table[key][i].first == word){
                this->table[key][i].second ++;
                cout << word << " inserted, new count = " << this->table[key][i].second << endl;
                return;
            }

        } 
        this->table[key].push_back(a);
        cout << word << " inserted, new count = " << a.second << endl;
    }
}

void HashTable::insertWordInitial(const string word){
    int key = this->Hash(word);
    std::pair<string, int> a (word, 1);
    if (this->table[key].empty()){
        this->table[key].push_back(a);
        
        return;
    }

    else{
        for(size_t i = 0; i < table[key].size(); i++){
            if (this->table[key][i].first == word){
                this->table[key][i].second ++;
                
                return;
            }

        } 
        this->table[key].push_back(a);
        
    }
}


void HashTable::searchWord(string word){
    int key = this->Hash(word);
    std::pair<string, int> a (word, 1);
    if (this->table[key].empty()){
        cout << word << " not found" << endl;
        return;
    }

    for(size_t i = 0; i < table[key].size(); i++){
            if (this->table[key][i].first == word){
                cout << word << " found, count = " << this->table[key][i].second << endl;
                return;
            }}
    cout << word << " not found" << endl;
    return;

    
}

void HashTable::deleteWord(string word){
    int key = this->Hash(word);
    std::pair<string, int> a (word, 1);
    if (this->table[key].empty()){
        cout << word << " not found" << endl;
        return;
    }

    else{
        for(size_t i = 0; i < table[key].size(); i++){
            if (this->table[key][i].first == word){
                this->table[key][i].second --;
                
                if (this->table[key][i].second == 0){
                    this->table[key].erase(this->table[key].begin()+i);
                    cout << word << " deleted\n";
                    return;
                }
                cout << word << " deleted, new count = " << this->table[key][i].second << endl;
                return;
            }
            
        }
        cout << word << " not found" << endl; 
        return;
    }



}

void HashTable::rangeSearch(std::string param1, std::string param2){
    vector <string> outs;
    for (int i = 0; i < 10000; i++){
        for (pair<string, int> i : table[i]){
            if (i.first >= param1 && i.first <= param2){
                outs.push_back(i.first);
            }
        }
    }
    std::sort(outs.begin(), outs.end());
    for (auto i : outs){
        cout << i << endl;
    }


}