#include <iostream>
#include "Clock.h"

int main() {
    Clock time = createClockInstance();

    int result1 = minutesUntilTheEndOfTheDay(time);
    int result2 = minutesUntilTheEndOfTheDay(time.hour, time.minute, time.second);
    int result3 = minutesUntilTheEndOfTheDay(time.hour, time.minute);
    std::cout << "Until the end of the day there are " 
                << result1 << " minutes left" << std::endl;
    std::cout << "Until the end of the day there are " 
                << result2 << " minutes left" << std::endl;
    std::cout << "Until the end of the day there are " 
                << result3 << " minutes left" << std::endl;
    return 0;
}