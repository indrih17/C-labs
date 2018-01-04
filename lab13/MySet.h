#include <iostream>
#include <vector>

/**
    THE IMPLEMENTATION OF CLASS TEMPLATE CAN'T REMOVED IN THE .CPP FILE!
*/

#ifndef MY_SET_H
#define MY_SET_H

template <typename T> class MySet {
private:
    std::vector<T> set;
public:
    MySet() {}
    MySet(MySet<T>* inp);
    MySet(T* inputArr, int size);

    ~MySet();

    int getCardinality() {
        return set.size();
    }

    bool contains(T t);
    void add(T t);
    void print();
    MySet<T>* intersection(MySet<T>* inputSet);
    MySet<T>* unions(MySet<T>* inputSet);
    MySet<T>* difference(MySet<T>* inputSet);
    MySet<T>* withoutIntersection(MySet<T>* inputSet);

    MySet<T>* operator * (MySet<T>* inputSet);
    MySet<T>* operator + (MySet<T>* inputSet);
    MySet<T>* operator - (MySet<T>* inputSet);
    T operator [] (int index);
};


//*******************Constructors************************

template <typename T> MySet<T>::MySet(MySet<T>* inputSet) {
    set = inputSet->set;
}

template <typename T> MySet<T>::MySet(T* inputArr, int size) {
    for (int i = 0; i < size; i++) {
        add(inputArr[i]);
    }
}

//*******************Destructor**************************

template <typename T> MySet<T>::~MySet() {
    for (int i = 0; i < set.size(); i++) {
        set[i].~T();
    }
    set.clear();
}

//*******************Functions***************************

template<typename T> bool MySet<T>::contains(T t) {
    for (int i = 0; i < set.size(); i++) {
        if (set[i] == t) {
            return true;
        }
    }
    return false;
}

template<typename T> void MySet<T>::add(T t) {
    if (!contains(t)) {
        set.push_back(t);
    }
} 

template<typename T> void MySet<T>::print() {
    for (int i = 0; i < set.size(); i++) {
        std::cout << set[i] << " ";
    } 
    std::cout << std::endl;
}

template<typename T> MySet<T>* MySet<T>::intersection(MySet<T>* inputSet) {
    MySet<T>* result = new MySet<T>();

    for (int i = 0; i < set.size(); i++) {
        if (inputSet->contains(set[i])) {
            result->add(set[i]);
        }
    }

    return result;
}

template<typename T> MySet<T>* MySet<T>::unions(MySet<T>* inputSet) {
    MySet<T>* result = new MySet<T>(inputSet);

    for (int i = 0; i < set.size(); i++) {
        result->add(set[i]);
    }

    return result;
}

template<typename T>  MySet<T>* MySet<T>::difference(MySet<T>* inputSet) {
    MySet<T>* result = new MySet<T>();

    for (int i = 0; i < this->set.size(); i++) {
        if (!inputSet->contains(this->set[i])) {
            result->add(this->set[i]);
        }
    }
    return result;
}

template<typename T> MySet<T>* MySet<T>::withoutIntersection(MySet<T>* B) {
    MySet<T>* unionSet = (*this) + B;
    MySet<T>* intersectionSet = (*this) * B;
    MySet<T>* result = (*unionSet) - intersectionSet;

    unionSet->~MySet();
    intersectionSet->~MySet();

    return result;
}

//*******************Operators***************************

template<typename T> MySet<T>* MySet<T>::operator * (MySet<T>* inputSet) {
    return intersection(inputSet);
}

template<typename T> MySet<T>* MySet<T>::operator + (MySet<T>* inputSet) {
    return unions(inputSet);
}

template<typename T> MySet<T>* MySet<T>::operator - (MySet<T>* inputSet) {
    return difference(inputSet);
}

template<typename T> T MySet<T>::operator [] (int index) {
    if (set.size() <= index) {
        throw "The current index is outside the set";
    }
    return set[index];
}

#endif