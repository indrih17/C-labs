#include <iostream>
#include <iomanip>
#include "Clock.h"

Clock createClock() {
    Clock clock;
    do {
        std::cout << "Enter the hour of departure: ";
        std::cin >> clock.hour;
        if (clock.hour > 23) {
            std::cerr << "Error: try again." << std::endl;
        }
    } while (clock.hour > 23);

    do {
        std::cout << "Enter the minute of departure: ";
        std::cin >> clock.minute;
        if (clock.minute > 60) {
            std::cerr << "Error: try again" << std::endl;
        }
    } while (clock.minute > 60);
    return clock;
}

void print(Clock clock) {
    std::cout << std::setw(2) << std::setfill('0') << clock.hour << ":";
    std::cout << std::setw(2) << std::setfill('0') << clock.minute << std::endl;
}