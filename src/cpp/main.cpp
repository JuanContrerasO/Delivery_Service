#include <iostream>
#include <limits> // for std::numeric_limits
#include "TripManager.h"
#include "TripLeg.h"

int main()
{
	std::cout << "\nWelcome to American Express Delivery Service\n";
	std::cout << "This software is maintained by Juan Contreras.\n";\
	std::cout << "For assistance contact the developer at Juan_Contreras@csu.fullerton.edu\n\n";
	
	TripManager trip;
	
	int num_legs = 0;
	const int MAX_LEGS = 200;
	do
	{
		std::cout << "Enter the number of legs you will need: ";
		std::cin >> num_legs;
		std::cout << "\n";
		
		//Check if input failed (non-numeric input)
		if(std::cin.fail())
		{
			std::cin.clear(); // clear the error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard invalid input
			std::cout << "Invalid input! Please enter a numeric value.\n\n";
			continue; //skip to next iteration
		}
		
		if(num_legs <= 0 || num_legs > MAX_LEGS)
		{
			std::cout << "Please enter a number of legs that is at least 1 and at most 200. Try again.\n\n";
		}
		
	}while (num_legs <= 0 || num_legs > MAX_LEGS);
	
	for (int i = 0; i < num_legs; ++i)
	{
		double distance = 0, speed = 0;
		
		do
		{
			std::cout << "Enter distance for leg " << i + 1 << " (miles): ";
			std::cin >> distance;
			if (std::cin.fail() || distance <= 0)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Distance must be a positive number. Please try again.\n";
			}
		} while (distance <= 0);
		
		do
		{
			std::cout << "Enter average speed for leg " << i + 1 << " (mph): ";
			std::cin >> speed;
			if (std::cin.fail() || speed <= 0)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Speed must be a positive number. Please try again.\n";
			}
		} while (speed <= 0);
		
		trip.addLeg(distance, speed);
		std::cout << "\n";
	}
	
	double total_time = trip.totalTime();
	int hours = static_cast<int>(total_time);
	int minutes = static_cast<int>((total_time - hours) * 60);
	
	double avg_speed = trip.averageSpeed();
	
	std::cout << "The total driving time was " << hours << " hours "<< "and " << minutes << " minutes.\n";
	std::cout << "The average speed was " << avg_speed << " mph\n";
	std::cout << "The driver received this number " << avg_speed << " and will keep it for future use.\n\n";

	std::cout << "Thank you for using our software. Have a nice day.\n";
	std::cout << "An integer zero will be returned to the operating system.\n";
	
	return 0;
}
