#ifndef TRIPMANAGER_H
#define TRIPMANAGER_H

#include "TripLeg.h"
#include <vector>

class TripManager
{

public:
	void addLeg(const TripLeg& leg);
	double totalTime() const;
	double totalDistance() const;
	double averageSpeed() const;
	
private:
	std::vector<TripLeg> legs;
};

#endif
