#include <iostream>
#include "Bus.h"
#include "Driver.h"

int main() {
    // start of the creation the list of buses
    int numberOfBuses;
    std::cout << "Enter the number of buses: ";
    std::cin >> numberOfBuses;

    if (numberOfBuses < 1) {
        std::cerr << "The number of buses is less than 1." << std::endl;
        std::cerr << "The list of buses will not be created." << std::endl;
        return -1;
    }

    Bus *busesList = (Bus*) operator new (sizeof(Bus) * numberOfBuses);

    for (int i = 0; i < numberOfBuses; i++) {
        new(&busesList[i]) Bus();
        busesList[i].createBus();
    }
    // end of the creation the list of buses

    std::cout << "Filter by number of the bus: ";
    int busNumber;
    std::cin >> busNumber;

    std::cout << "Result\n\n";
    for (int i = 0; i < numberOfBuses; i++) {
        if (busNumber == busesList[i].getBusNumber()) {
            busesList[i].printBusInfo();
        }
    }

    std::cout << "Filter by year of aging of the bus: ";
    int year;
    std::cin >> year;

    std::cout << "Result\n\n";
    for (int i = 0; i < numberOfBuses; i++) {
        if (2017 - year > busesList[i].getYearOfOperation()) {
            busesList[i].printBusInfo();
        }
    }

    std::cout << "Filter by mileage: ";
    int mileage;
    std::cin >> mileage;

    std::cout << "Result\n\n";
    for (int i = 0; i < numberOfBuses; i++) {
        if (mileage < busesList[i].getMileage()) {
            busesList[i].printBusInfo();
        }
    }

    for (int i = 0; i < numberOfBuses; i++) {
        busesList[i].~Bus();
    }
    // memory cleaning
    delete busesList;
    return 0;
}