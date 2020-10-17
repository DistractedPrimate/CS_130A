


#include <iostream> 
#include <utility> 
#include <string>
#include "bst.h"
#include "hash.h"
#include <sstream>
#include <fstream>
#include <ostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*search hello, insert goodbye, delete yesterday, insert hello, delete goodbye, range search band
to cat*/
int main(int argc, const char *argv[]){
    BST tree;
    HashTable table;
    string line;
    
    ifstream ifs;
    ifs.open("/autograder/submission/PA1_dataset.txt");
    //ifs.open("PA1_dataset.txt");
    //std::cout.setstate(std::ios_base::failbit);
    while(ifs) {
        getline(ifs, line);
        tree.insertWordInitial(line.substr(0, line.size() - 1));
        table.insertWordInitial(line.substr(0, line.size()-1));
    }

    ifs.close();
    //std::cout.clear();
    vector<string> a;
    
    string line2 = argv[1];
    string in;
    for (auto x : line2){
        if (x==' '){
            a.push_back(in);
            in = "";
        }
        else{
            in = in+x;
        }
    }
    a.push_back(in);

    for(int j = 0; j < a.size(); j++){
        for(int k=0; k < a[j].size(); k++){
            if(!isalpha(a[j].at(k))){
                a[j].erase(k);
            }
        }
    }

    
    string range = "range";
    string search = "search";
    string insert = "insert";
    string deLete = "delete";
   

    for (int z = 0; z < a.size(); z++){
        if (search.compare(a[z])==0){
            tree.searchWord(a[z+1]);
            table.searchWord(a[z+1]);
        }
    
        if (insert.compare(a[z])==0){
            tree.insertWord(a[z+1]);
            table.insertWord(a[z+1]);
        }

        else if (deLete.compare(a[z])==0){
            tree.deleteWord(a[z+1]);
            table.deleteWord(a[z+1]);
        }

        else if (range.compare(a[z])==0){
            z++;
            tree.rangeSearch(a[z+1], a[z+3]);
            table.rangeSearch(a[z+1], a[z+3]);
    
        }
    }

    /*
    if (strcmp("search",a[z])==0){
        tree.searchWord(argv[2]);
        table.searchWord(argv[2]);
    }
    
    if (strcmp("insert",a[z])==0){
        tree.insertWord(argv[2]);
        table.insertWord(argv[2]);
    }

    else if (strcmp("delete",a[z])==0){
        tree.deleteWord(argv[2]);
        table.deleteWord(argv[2]);
    }

    else if (strcmp("range",a[z])==0){
        tree.rangeSearch(argv[3], argv[5]);
        table.rangeSearch(argv[3], argv[5]);
    
    }

    /*
    if ("search"==argv[1]){
        tree.searchWord(argv[2]);
        table.searchWord(argv[2]);
    }
    
    if ("insert"==argv[1]){
        tree.insertWord(argv[2]);
        table.insertWord(argv[2]);
    }

    else if ("delete"==argv[1]){
        tree.deleteWord(argv[2]);
        table.deleteWord(argv[2]);
    }

    else if ("range"==argv[1]){
        tree.rangeSearch(argv[3], argv[5]);
        table.rangeSearch(argv[3], argv[5]);
    
    }*/


    return 0;
}