
#include <iostream> 
#include <utility> 
#include <string>
#include <vector>

class minmaxheap {
    
    public:
        // Default Constructors
        minmaxheap() {this->heap.push_back(88888);}
        //~minmaxheap();

        /*getMin: It returns the minimum value in the min-max heap. If the heap is empty, it
        should return zero. This operation should be done in O(1).*/
        int getMin();
        
        /*getMax: It returns the maximum value in the min-max heap. If the heap is empty, it
        should return zero. This operation should be done in O(1).*/
        int getMax();

        /*(c) insert: It inserts a value into the min-max heap. The min-max heap properties need to
        be maintained after the insertion. This operation should be done in O(log N).*/
        void insert(int n);

        /*(d) deleteMin: It deletes the minimum value in the min-max heap. The min-max heap
        properties need to be maintained after the deletion. This operation should be done in
        O(log N).*/
        void deleteMin();

        /*(e) deleteMax: It deletes the maximum value in the min-max heap. The min-max heap
        properties need to be maintained after the deletion. This operation should be done in
        O(log N).*/
        void deleteMax();

        /*(f) printHeap: It prints all the elements in the heap array in the order they appear in the
        array. This operation should be done in O(n) time.*/
        void printHeap();

        //bool getLevel() {return minlevel};
        void insertInitial(int n);

    private:
        std::vector<int> heap;
        void bubbleup(size_t i, bool maxlevel);
        void bubbledown(size_t i);
        void bubbledownmin(size_t i);
        void bubbledownmax(size_t i);
        int getMaxHelper();
};