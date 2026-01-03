#ifndef TRIPMANAGER_H
#define TRIPMANAGER_H

#include "TripLeg.h"
#include <vector>

class TripManager
{
public:
    void addLeg(double distance, double speed);

    double totalTime() const;
    double averageSpeed() const;
    int numberOfLegs() const;

private:
    std::vector<TripLeg> legs;
};

#endif
