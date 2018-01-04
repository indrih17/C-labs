#include <iostream>
#include "MySet.h"

MySet<int>* createSet() {
    int size;
    std::cout << "Enter the cardinality of the new set: ";
    std::cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Enter the " << i+1 << " element: ";
        std::cin >> arr[i];
    }
    MySet<int>* set = new MySet<int>(arr, size);
    return set;
}

int main() {
    MySet<int>* set1 = createSet();
    MySet<int>* set2 = createSet();

    std::cout << "Without intersection: ";
    MySet<int>* set3 = set1->withoutIntersection(set2);
    set3->print();

    // memory cleaning
    set1->~MySet(); 
    set2->~MySet(); 
    set3->~MySet();
    return 0;
}