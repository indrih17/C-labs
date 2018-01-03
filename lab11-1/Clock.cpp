#include <iostream>
#include <iomanip>
#include "Clock.h"

Clock createClockInstance() {
    std::cout << "\nCreating a new clock.\n";
    Clock current;
    do {
        std::cout << "Enter the current hour: ";
        std::cin >> current.hour;
        if (current.hour > 23) {
            std::cerr << "Error: try again." << std::endl;
        }
    } while (current.hour > 23);
    do {
        std::cout << "Enter the current minute: ";
        std::cin >> current.minute;
        if (current.minute > 60) {
            std::cerr << "Error: try again." << std::endl;
        }
    } while (current.minute > 23);
    do {
        std::cout << "Enter the current second: ";
        std::cin >> current.second;
        if (current.second > 60) {
            std::cerr << "Error: try again." << std::endl;
        }
    } while (current.second > 23);

    return current;
}

void print(Clock current) {
    std::cout << std::setw(2) << std::setfill('0') << current.hour << ":";
    std::cout << std::setw(2) << std::setfill('0') << current.minute << ":";
    std::cout << std::setw(2) << std::setfill('0') << current.second << std::endl;
}


int minutesUntilTheEndOfTheDay(Clock current) {
    int secondsInDay = 86400;
    int secondsPassed = current.hour * 3600 + current.minute * 60 + current.second;
    return (secondsInDay - secondsPassed) / 60;
}

int minutesUntilTheEndOfTheDay(unsigned short hour,  
                                unsigned short minute, 
                                unsigned short second) 
{
    int secondsInDay = 86400;
    int secondsPassed = hour*3600 + minute*60 + second;
    return (secondsInDay - secondsPassed) / 60;
}

int minutesUntilTheEndOfTheDay(unsigned short hour, unsigned short minute) {
    int minutesInDay = 1440;
    int minutesPassed = hour * 60 + minute;
    return minutesInDay - minutesPassed;
}