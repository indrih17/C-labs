#include <iostream>
#include <ctime>
#include "Date.h"

Date createDate() {
    std::cout << "\nCreating a new date.\n";
    Date date;
    std::cout << "Enter the year: ";
    std::cin >> date.year;

    std::cout << "Enter the month: ";
    std::cin >> date.month;

    std::cout << "Enter the day: ";
    std::cin >> date.day;

    return date;
}

Date calculateCurrentDate() {
    struct tm *tim;
    time_t tt = time(NULL);
    tim = localtime(&tt);

    Date result;
    result.year = tim->tm_year + 1900;
    result.month = tim->tm_mon;
    result.day = tim->tm_mday;

    return result;
}

bool compareDate(Date date) {
    Date current = calculateCurrentDate();
    return (date.year == current.year &&
            date.month == current.month &&
            date.day == current.day);
}

bool compareDate(unsigned short year,
                 unsigned short month,
                 unsigned short day) 
{
    Date current = calculateCurrentDate();
    return (year == current.year &&
            month == current.month &&
            day == current.day);
}

bool compareDate(unsigned short month,
                 unsigned short day) 
{
    Date current = calculateCurrentDate();
    return (month == current.month &&
            day == current.day);
}