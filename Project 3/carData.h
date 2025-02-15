#pragma once

#include <iostream>
#include <string>

class Car {
public:
	/* Constructors */
	Car();
	Car(int year, std::string make, std::string model, int cityMPG, int highwayMPG);
	Car& operator=(const Car& other);

	/* Overloaded Operators */
	bool operator==(const Car& other);
	bool operator<(const Car& other);
	bool operator>(const Car& other);

	/* Getters */
	int getYear() const;
	std::string getMake() const;
	std::string getModel() const;
	int getCityMPG() const;
	int getHighwayMPG() const;
	int getAvgMPG() const;
	std::string getSearchString();

private:
	int year;
	std::string make;
	std::string model;
	int cityMPG;
	int highwayMPG;
	int avgMPG;
};
