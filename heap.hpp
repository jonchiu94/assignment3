#include <vector>
#include <iostream>
#include <algorithm>
#pragma once

using namespace std;

template <typename T>
class heap {
    private:
        // vector to store heap element
        vector<T> heap_vector;

        //Returns the location of parent
        T PARENT(int i) {
            return (i - 1) / 2;
        }

        // returns position of left child
        T LEFT(int i) {
            return (2 * i + 1);
        }

        // return position of right child
        T RIGHT(int i) {
            return (2 * i + 2);
        }

        //Heapifies the vector
        void heapify() {
            for (unsigned int i = 0; i < heap_vector.size(); i++) {
                heapify_down(i);
            }
        }
        // Recursive Heapify-down algorithm
        void heapify_down(int i) {
            unsigned int left = LEFT(i);
            unsigned int right = RIGHT(i);
            int largest = i;
            if (left < heap_vector.size() && heap_vector[left] > heap_vector[i])
                largest = left;
            if (right < heap_vector.size() && heap_vector[right] > heap_vector[largest])
                largest = right;
            if (largest != i) {
                swap(heap_vector[i], heap_vector[largest]);
                heapify_down(largest);
            }
        }
    public:
        heap(vector<T> input){
            heap_vector = {};
            for(unsigned int i = 0; i < input.size(); i++){
                heap_vector.push_back(input[i]);
            }
            heapify();
        }
        //clears the heap
        void clear(){
            heap_vector.clear();
        }
        // function to check if heap is empty or not
        bool is_empty() {
            return heap_vector.size() == 0;
        }
        // insert an element into the heap
        void push(T key) {
            heap_vector.push_back(key);
            heapify();
        }
        // takes the root element and returns it
        //heapifies vector afterwards
        T pop() {
                T temp = heap_vector[0];
            heap_vector[0] = heap_vector.back();
            heap_vector.pop_back();
                heapify();
                return temp;
        }
        //returns the size of heap
        unsigned long size(){
            return heap_vector.size();
        }
        //friend overloaded insertion operator
        //returns all items in heap
    friend ostream &operator<< (ostream &os, const heap &A){
        for(unsigned int i = 0; i < A.heap_vector.size(); i++){
            os << A.heap_vector[i] << " ";
        }
        return os;
    }
};


