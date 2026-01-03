#ifndef TRIPLEG_H
#define TRIPLEG_H

#include "trip.h"

class TripLeg
{
	
public:
	TripLeg(double d = 0.0, double s = 0.0);
	void set(double d, double s);
	double getDistance() const;
	double getSpeed() const;
	double computeTime() const; //Calls ASM function

private:
	double distance;
	double speed;
};

#endif
