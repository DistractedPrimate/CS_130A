
#include <iostream> 
#include <utility> 
#include <vector>
#include <math.h>
#include "minmax.h"
using namespace std;


int minmaxheap::getMin(){
    
    if (this->heap.size()==1){
        return 0;
    }
    
    // return first element
    cout << "min = " << heap[1] << endl;
    return heap[1];
}

int minmaxheap::getMax(){
    
    if (this->heap.empty()){
        return 0;
    }
    
    // return first element
    // Do case of arr of size 1,2
    if (this->heap[2]>this->heap[3]){
        cout << "max = " << heap[2] << endl;
        return heap[2];
    }
    cout << "min = " << heap[3] << endl;
    return heap[3];

}

int minmaxheap::getMaxHelper(){
    
    if (this->heap.empty()){
        return 0;
    }
    
    // return first element
    // Do case of arr of size 1,2
    if (this->heap[2]>this->heap[3]){
        
        return heap[2];
    }
    
    return heap[3];

}

void minmaxheap::insert(int n){
    this->heap.push_back(n);
    cout << "inserted " << n << endl;
    size_t level = heap.size()-1;
    // if this is odd, we are on a min level, otherwise we are on a max level
    int lowerbound = int(floor(log2(double(level))));
    //cout << "lowerbound: " << lowerbound << endl;
    bool maxlevel = true;
    if (lowerbound % 2 == 0){
        maxlevel = false;
    }
    
    this->bubbleup(heap.size()-1, maxlevel);

}

void minmaxheap::deleteMin(){
    cout << "deleted " << heap[1] << endl;
    std::swap(this->heap[1], this->heap[heap.size()-1]);
    this->heap.pop_back();
    bubbledownmin(1);

}

void minmaxheap::deleteMax(){
    if (this->heap[2]==this->getMaxHelper()){
        cout << "deleted " << heap[2] << endl;
        std::swap(this->heap[2], this->heap[heap.size()-1]);
        this->heap.pop_back();
        bubbledownmax(2);
  
    }
    else{
        cout << "deleted " << heap[3] << endl;
        std::swap(this->heap[3], this->heap[heap.size()-1]);
        this->heap.pop_back();
        bubbledownmax(3);
 
    }
}

void minmaxheap::bubbleup(size_t i, bool maxlevel){
    size_t grandparent = i/4;
    size_t parent = i/2;
    if (parent == 0 || i == 0){
        return;
    }

    // Max level
    if (maxlevel)
        // max is less than min parent, swap with min parent
        if (heap[i] < heap[parent]){
            std::swap(heap[i],heap[parent]);
            this->bubbleup(parent, false);
        }   
        // max is greater than max grandparent, swap with max grandparent
        else if (heap[i] > heap[grandparent] && grandparent != 0){
            std::swap(heap[i], heap[grandparent]);
            this->bubbleup(grandparent, true);
        
        }
        // element is in the right place
        else return;
    // Min Level
    else{
        // min is greater than max parent, swap with max parent
        if (heap[i] > heap[parent]){
            std::swap(heap[i],heap[parent]);
            this->bubbleup(parent, true);
        }   
        // min is less than min grandparent, swap with min grandparent
        else if (heap[i] < heap[grandparent] && grandparent != 0){
            std::swap(heap[i], heap[grandparent]);
            this->bubbleup(parent, false);
        }
        // element is in the right place
        else return;
    }

}


void minmaxheap::bubbledownmin(size_t i){
    size_t childrenIndex = 2*i;
    if (childrenIndex>this->heap.size()-1){
        return;
    }
    
    // Check all the possible nodes that could be swapped on the elements path down
    size_t grandChildrenIndex = 4*i;
    vector<size_t> canidates;
    canidates.push_back(2*i);
    canidates.push_back(2*i+1);
    canidates.push_back(4*i);
    canidates.push_back(4*i+1);
    canidates.push_back(4*i+2);
    canidates.push_back(4*i+3);
    size_t minIndex = childrenIndex;

    for (auto canidate : canidates){
        if (canidate < this->heap.size()){
            if (this->heap.at(canidate) < this->heap.at(minIndex)){
                minIndex = canidate;
            }
        }
    }


    if ((minIndex >= (4*i)) && (minIndex <= (4*i+3))){
        if(this->heap.at(minIndex) < this->heap.at(i)){
            std::swap(this->heap[minIndex], this->heap[i]);
            if (this->heap.at(minIndex) > this->heap.at(minIndex/2)){
                std::swap(this->heap[minIndex], this->heap[minIndex/2]);
            }
        this->bubbledownmin(minIndex);
        }
    }

    else{
        if (this->heap[minIndex] < this->heap[i]){
            std::swap(this->heap[minIndex], this->heap[i]);
        }
    }

    

}

void minmaxheap::bubbledownmax(size_t i){
    size_t childrenIndex = 2*i;
    if (childrenIndex>this->heap.size()-1){
        return;
    }
    size_t grandChildrenIndex = 4*i;
    // Check all the possible nodes that could be swapped on the elements path down
    vector<size_t> canidates;
    canidates.push_back(2*i);
    canidates.push_back(2*i+1);
    canidates.push_back(4*i);
    canidates.push_back(4*i+1);
    canidates.push_back(4*i+2);
    canidates.push_back(4*i+3);
    size_t minIndex = childrenIndex;


    for (auto canidate : canidates){
        if (canidate < this->heap.size()){
           if (this->heap.at(canidate) > this->heap.at(minIndex)){
                minIndex = canidate;
            }
        }
    }

    if ((minIndex >= (4*i)) && (minIndex <= (4*i+3))){
        if(this->heap.at(minIndex) > this->heap.at(i)){
            std::swap(this->heap[minIndex], this->heap[i]);
            if (this->heap.at(minIndex) < this->heap.at(minIndex/2)){
                std::swap(this->heap[minIndex], this->heap[minIndex/2]);
            }
        this->bubbledownmax(minIndex);
        }
    }

    else{
        if (this->heap[minIndex] > this->heap[i]){
            std::swap(this->heap[minIndex], this->heap[i]);
        }
    }

    

}


void minmaxheap::printHeap(){
    cout << "heap = "; 
    for (size_t i = 1; i<this->heap.size(); i++)
        cout << heap[i] << " ";
    cout << endl;
}

void minmaxheap::insertInitial(int n){
    
    this->heap.push_back(n);
    size_t level = heap.size()-1;
    // if this is odd, we are on a min level, otherwise we are on a max level
    int lowerbound = int(floor(log2(double(level))));
    //cout << "lowerbound: " << lowerbound << endl;
    bool maxlevel = true;
    if (lowerbound % 2 == 0){
        maxlevel = false;
    }
    
    this->bubbleup(heap.size()-1, maxlevel);

}

