#include "Driver.h"

#ifndef BUS_H
#define BUS_H

class Bus {
private:
    Driver driver;
    int busNumber;
    int routeNumber;
    std::string brand;
    int yearOfOperation;
    int mileage;

public:
    Driver getDriver() {
        return driver;
    }
    void setDriver(Driver driver) {
        this->driver = driver;
    }

    int getBusNumber() {
        return busNumber;
    }
    void setBusNumber(int busNumber) {
        this->busNumber = busNumber;
    }

    int getRouteNumber() {
        return routeNumber;
    }
    void setRouteNumber(int routeNumber) {
        this->routeNumber = routeNumber;
    }

    std::string getBrand() {
        return brand;
    }
    void setBrand(std::string brand) {
        this->brand = brand;
    }

    int getYearOfOperation() {
        return yearOfOperation;
    }
    void setYearOfOperation(int yearOfOperation) {
        this->yearOfOperation = yearOfOperation;
    }

    int getMileage() {
        return mileage;
    }
    void setMileage(int mileage) {
        this->mileage = mileage;
    }


    void createBus();
    void printBusInfo();
};

#endif