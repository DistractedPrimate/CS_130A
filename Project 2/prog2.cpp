
#include <iostream> 
#include <utility> 
#include <string>
#include "minmax.h"
#include <sstream>
#include <fstream>
#include <ostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;


int main(int argc, const char *argv[]){
    minmaxheap heap;
    string line;
    
    ifstream ifs;
    ifs.open("/autograder/submission/PA2_dataset.txt");
    //ifs.open("PA1_dataset.txt");
    //std::cout.setstate(std::ios_base::failbit);
    while(ifs) {
        while(getline(ifs, line)){
            int input = stoi(line);
            heap.insertInitial(input);
        }
        //heap.insert(stoi(line.substr(0, line.size() - 1)));

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

    
    string getMin = "getMin";
    string getMax = "getMax";
    string insert = "insert";
    string deleteMin = "deleteMin";
    string deleteMax = "deleteMax";
    string printHeap = "printHeap";
   

    for (int z = 0; z < a.size(); z++){
        if (getMin.compare(a[z])==0){
            heap.getMin();
        }
    
        if (getMax.compare(a[z])==0){
            heap.getMax();
        }

        else if (insert.compare(a[z])==0){
            heap.insert(stoi(a[z+1]));
        }

        else if (deleteMin.compare(a[z])==0){
            heap.deleteMin();
        }

        else if (deleteMax.compare(a[z])==0){
            heap.deleteMax();
        }

        else if (printHeap.compare(a[z])==0){
            heap.printHeap();
        }
        else{
            cout << "I can't see :(\n" << z << endl;
        }
    }
    return 0;

}
