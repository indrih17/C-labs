#ifndef CLOCK_H
#define CLOCK_H 

struct Clock {
    unsigned short hour;
    unsigned short minute;
};
 
Clock createClock();

void print(Clock);

#endif