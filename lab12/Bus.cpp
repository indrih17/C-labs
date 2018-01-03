#include <iostream>
#include <ctime>
#include "Bus.h"

void Bus::createBus() {
    std::cout << "\nThe creation of information about the new bus.\n";
    std::cout << "Enter driver surname: ";          std::cin >> driver.surname;
    std::cout << "Enter driver initials: ";         std::cin >> driver.initials;
    std::cout << "Enter the number of the bus: ";   std::cin >> busNumber;
    std::cout << "Enter the number of the route: "; std::cin >> routeNumber; 
    std::cout << "Enter the brand: ";               std::cin >> brand;
    std::cout << "Enter the year of operation: ";   std::cin >> yearOfOperation;
    std::cout << "Enter the mileage: ";             std::cin >> mileage;
}

void Bus::printBusInfo() {
    std::cout << "Driver: " << driver.initials << " " << driver.surname << std::endl;
    std::cout << "The number of the bus: " << busNumber << std::endl;
    std::cout << "The number of the route: " << routeNumber << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "The year of operation: " << yearOfOperation << std::endl;
    std::cout << "Mileage: " << mileage << std::endl;
    std::cout << std::endl;
}