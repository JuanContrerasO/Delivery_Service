#include "TripManager.h"
#include "trip.h"

void TripManager::addLeg(const TripLeg& leg) { legs.push_back(leg); }

double TripManager::totalTime() const
{
	double sum = 0.0;
	for (const auto& leg : legs)
	{
		sum = ::add(sum, leg.ComputeTime());
	}
	return sum;
}

double TripManager::totalDistance() const
{
	double sum = 0.0;
	for (const auto& leg : legs)
	{
		sum = ::add(sum, leg.getDistance());
	}
	return sum;
}

double TripManager::averageSpeed() const
{
	double time = totalTime();
	if (time == 0) { return 0; }
	return totalDistance() / time;
}


















