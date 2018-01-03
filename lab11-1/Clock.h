#ifndef CLOCK_H
#define CLOCK_H 

struct Clock {
    unsigned short hour;
    unsigned short minute;
    unsigned short second;
};

Clock createClockInstance();
void print(Clock);

int minutesUntilTheEndOfTheDay(Clock);
int minutesUntilTheEndOfTheDay(unsigned short, unsigned short, unsigned short);
int minutesUntilTheEndOfTheDay(unsigned short, unsigned short);

#endif