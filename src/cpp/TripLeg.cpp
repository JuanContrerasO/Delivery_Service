#include "TripLeg.h"

TripLeg::TripLeg(double d, double s) : distance(d), speed(s) {}

void TripLeg::set(double d, double s)
{
	distance = d;
	speed = s;
}

double TripLeg::getDistance() const { return distance; }
double TripLeg::getSpeed() const { return speed; }

double TripLeg::ComputeTime() const { return ::compute_time(distance, speed); }
