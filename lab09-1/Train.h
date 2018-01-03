#include "Clock.h"

#ifndef TRAIN_H
#define TRAIN_H 

struct Train {
    std::string destination;
    unsigned int number;
    Clock departureTime;
};

Train createTrain();
void print(Train);

#endif