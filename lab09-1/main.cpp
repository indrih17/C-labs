#include <iostream>
#include <iomanip>
#include "Train.h"
#include "Clock.h"


int main() {
    // start of train creation
    int trainsNumber;
    std::cout << "Enter the trains number: ";
    std::cin >> trainsNumber;
    if (trainsNumber < 1) {
        std::cerr << "The number of trains is less than 1." << std::endl;
        std::cerr << "List of trains will not be created." << std::endl;
        return -1;
    }
    // end of train creation

    Train *listOfTrains = new Train[trainsNumber];
    for (int i = 0; i < trainsNumber; i++) {
        listOfTrains[i] = createTrain();
    }

    std::cout << "\nFilter of train list.\n";
    Clock clock = createClock();
    std::cout << "\nResults:\n";

    bool requiredTrainExists = false;
    for (int i = 0; i < trainsNumber; i++) {
        Train train = listOfTrains[i];
        Clock departureTime = train.departureTime;

        if (departureTime.hour > clock.hour ||
            (departureTime.hour == clock.hour && departureTime.minute >= clock.minute))
        {
            requiredTrainExists = true;
            print(train);
        }
    }
    if (requiredTrainExists == false) {
        std::cout << "The required train does not exist." << std::endl;
    }

    // memory clearing
    for (int i = 0; i < trainsNumber; i++) {
        listOfTrains[i].~Train();
    }
    delete[] listOfTrains;
    return 0;
}