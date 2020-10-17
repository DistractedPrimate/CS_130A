
#include <iostream> 
#include <utility> 
#include <string>
#include <cmath>
#include <sstream>
#include <fstream>
#include <ostream>
#include <fstream>
#include "AVL.h"
#include "25Tree.h"
using namespace std;

int main(int argc, const char *argv[]){
    AVL tree;
    TwoThree tree2;
    string line;
    
    ifstream ifs;
    ifs.open("/autograder/submission/PA3_dataset.txt");
    //ifs.open("PA1_dataset.txt");
    std::cout.setstate(std::ios_base::failbit);
    
    while(getline(ifs, line)){
        
        //cout << line.substr(0, line.size() - 1) << endl;
        if (line != "")
            //cout << line << endl;
            tree.insertWord(line.substr(0, line.size() - 1));
            tree2.insert(line.substr(0, line.size() - 1));
        //heap.insert(stoi(line.substr(0, line.size() - 1)));
    }
    std::cout.clear();
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
            tree2.search(a[z+1]);
        }
    
        if (insert.compare(a[z])==0){
            tree.insertWord(a[z+1]);
            tree2.insert(a[z+1]);
        }

        /*else if (deLete.compare(a[z])==0){
            tree.deleteWord(a[z+1]);
            tree2.deleteWord(a[z+1]);
        }*/

        else if (range.compare(a[z])==0){
            z++;
            tree.rangeSearch(a[z+1], a[z+3]);
            tree2.rangeSearch(a[z+1], a[z+3]);
    
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