#include <iostream>
#include "heap.hpp"
int main() {
    vector<int> input {12,14,67,8,9,0};
    heap<int> heap1(input);
    int temp = heap1.pop();
    cout<<temp << "\r\n";
    cout<< heap1 << "\r\n";
    heap1.push(13);
    cout<< heap1 << "\r\n";
    heap1.clear();
    cout<< heap1 << "\r\n";
    return 0;
}