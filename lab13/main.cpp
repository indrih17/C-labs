#include <iostream>

//*********************class MySet****************************

template <typename T> class MySet {
private:
    T* set;
    int cardinality;
    int emptyPos;

    int numberOfTheSameElements(MySet<T>* inp) {
        int sameElements = 0;
        for (int i = 0; i < cardinality; i++) {
            if (inp->contains(this->set[i])) {
                sameElements++;
            }
        }
        return sameElements;
    }
    
public:
    MySet(int cardinality);
    MySet(MySet<T>* inp);
    MySet(int cardinality, MySet<T>* inp);
    MySet(T* inputArr, int size);
    MySet(int cardinality, T* inputArr, int size);

    ~MySet();

    int getCardinality() {
        return cardinality;
    }

    bool contains(T t);
    void add(T t);
    MySet<T>* intersection(MySet<T>* inp);
    MySet<T>* unions(MySet<T>* inp);
    MySet<T>* difference(MySet<T>* inp);


    MySet<T>* operator * (MySet<T>* inp) {
        return intersection(inp);
    }
    MySet<T>* operator + (MySet<T>* inp) {
        return unions(inp);
    }
    MySet<T>* operator - (MySet<T>* inp) {
        return difference(inp);
    }
    T operator [] (int index) {
        if (index >= cardinality) throw "The current index is outside the set";
        else if (index >= emptyPos) throw "No item found for the current index";
    
        return set[index];
    }
};

template <typename T> MySet<T>::MySet(int cardinality) {
    this->cardinality = cardinality;

    set = new T[cardinality];

    emptyPos = 0;
}

template <typename T> MySet<T>::MySet(MySet<T>* inp) {
    this->cardinality = inp->cardinality;

    set = new T[cardinality];
    for (int i = 0; i < cardinality; i++) {
        this->set[i] = inp->set[i];
    }

    emptyPos = cardinality;
}

template <typename T> MySet<T>::MySet(int cardinality, MySet<T>* inp) {
    if (cardinality < inp->cardinality) {
        throw "The cardinality of the new set is less than the cardinality of the input set";
    }
    this->cardinality = cardinality;

    set = new T[cardinality];
    for (int i = 0; i < inp->cardinality; i++) {
        this->set[i] = inp->set[i];
    }

    this->emptyPos = inp->cardinality;
}

template <typename T> MySet<T>::MySet(T* inputArr, int size) {
    int cardinality = size;
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (inputArr[i] == inputArr[j]) {
                cardinality--;
            }
        }
    }
    this->cardinality = cardinality;

    set = new T[cardinality];
    if (cardinality == size) {
        for (int i = 0; i < size; i++) {
            set[i] = inputArr[i];
        }
    } else {
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (!contains(inputArr[i])) {
                set[j] = inputArr[i];
                j++;
            }
        }
    }

    emptyPos = cardinality;
}

template <typename T> MySet<T>::MySet(int cardinality, T* inputArr, int size) {
    if (cardinality < size) {
        throw "The cardinality of the new set is less than the size of the input array";
    }
    this->cardinality = cardinality;

    set = new T[cardinality];
    for (int i = 0; i < size; i++) {
        set[i] = inputArr[i];
    }

    emptyPos = size;
}

template <typename T> MySet<T>::~MySet() {
    for (int i = 0; i < cardinality; i++) {
        set[i].~T();
    }
    delete set;
}

template<typename T> bool MySet<T>::contains(T t) {
    int i = 0;
    while (i < emptyPos) {
        if (set[i] == t) {
            return true;
        }
        i++;
    }
    return false;
}

template<typename T> void MySet<T>::add(T t) {
    if (!contains(t)) {
        if (emptyPos == cardinality) {
            throw "The set is full";
        }
        set[emptyPos] = t;
        emptyPos++;
    }
} 

template<typename T> MySet<T>* MySet<T>::intersection(MySet<T>* inp) {
    int same = numberOfTheSameElements(inp);
    MySet<T>* result = new MySet<T>(same);

    for (int i = 0; i < cardinality; i++) {
        if (inp->contains(this->set[i])) {
            result->add(this->set[i]);
        }
    }

    return result;
}

template<typename T> MySet<T>* MySet<T>::unions(MySet<T>* inp) {
    int same = numberOfTheSameElements(inp);

    MySet<T>* result = new MySet<T>(inp->cardinality + this->cardinality - same, inp);
    for (int i = 0; i < cardinality; i++) {
        result->add(this->set[i]);
    }

    return result;
}

template<typename T>  MySet<T>* MySet<T>::difference(MySet<T>* inp) {
    int same = numberOfTheSameElements(inp);
    MySet<T>* result = new MySet<T>(cardinality - same);

    for (int i = 0; i < cardinality; i++) {
        if (!inp->contains(this->set[i])) {
            result->add(this->set[i]);
        }
    }

    return result;
}

//****************************MAIN********************************

template<typename T> MySet<T>* withoutIntersection(MySet<T>* A, MySet<T>* B) {
    MySet<T> first = (*A) + B;
    MySet<T> second = (*A) * B;
    MySet<T>* result = new MySet<T>(first - &second);
    return result;
}

int main() {
    int size;
    std::cout << "Enter the cardinality of the first set: ";
    std::cin >> size;

    int* first = new int[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Enter the " << i+1 << " element: ";
        std::cin >> first[i];
    }
    MySet<int>* set1 = new MySet<int>(first, size);

    std::cout << "Enter the cardinality of the second set: ";
    std::cin >> size;

    int* second = new int[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Enter the " << i+1 << " element: ";
        std::cin >> second[i];
    }
    MySet<int>* set2 = new MySet<int>(second, size);

    std::cout << std::endl;

    MySet<int>* set3 = withoutIntersection(set1, set2);
   
    for (int i = 0; i < set3->getCardinality(); i++) {
        std::cout << (*set3)[i] << " ";
    }
    std::cout << std::endl;

    set1->~MySet(); 
    set2->~MySet(); 
    set3->~MySet();
    return 0;
}