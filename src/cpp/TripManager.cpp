#include "TripManager.h"

void TripManager::addLeg(double distance, double speed)
{
    legs.emplace_back(distance, speed);
}

double TripManager::totalTime() const
{
    double total = 0.0;
    for (const auto& leg : legs)
    {
        total += leg.computeTime();  // make sure capitalization matches
    }
    return total;
}

double TripManager::averageSpeed() const
{
    double totalDistance = 0.0;
    double totalTime_ = totalTime();

    for (const auto& leg : legs)
    {
        totalDistance += leg.getDistance();
    }

    return totalDistance / totalTime_;
}

int TripManager::numberOfLegs() const
{
    return legs.size();
}
