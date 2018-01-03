#include <iostream>
#include "Train.h"
#include "Clock.h"

Train createTrain() {
    Train train;
    std::cout << "\nCreating a new train.\n";

    std::cout << "Enter the name of destination: ";
    std::cin >> train.destination;

    std::cout << "Enter the number of train: ";
    std::cin >> train.number;

    train.departureTime = createClock();
    return train;
}

void print(Train train) {
    std::cout << train.destination << ", №";
    std::cout << train.number << ", ";
    print(train.departureTime);
}