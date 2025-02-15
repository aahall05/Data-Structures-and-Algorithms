#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "controller.h"

bool VerifyInput(std::string input) {
	int spaceCount = 0;
	if (input.size() == 0) {
		return false;
	}
	for (int i = 0; i < input.size(); i++) {
		// make sure first four characters are digits
		if (i < 4 && !isdigit(input[i])) {
			return false;
		}
		if(input[i] == ' ') {
			spaceCount++;
		}
	}
	// check if year is between 1950 and 2024
	int year = stoi(input.substr(0, 4));
	if (year < 1950 || year > 2024) {
		std::cout << "Year must be between 1950 and 2024" << std::endl;
		return false;
	}
	/*
		if the year is valid, and if there are at least two spaces,
		it follows the required format for the getline()functions that 
		follow, then we can search if it's in the data set.
	*/ 
	if(spaceCount < 2) {
		return false;
	}
	return true;
}

int main() {
	bool done = false;

	std::string input;
	std::string year;
	std::string make;
	std::string model;
	int distance;
	int passengers;

	EmmissionsData test;
	
	while (!done) {
		std::cout << "Enter the year, make, and model of your car (one space between each): ";
		std::getline(std::cin, input);
		
		// check if input is valid
		if (VerifyInput(input)) {
			std::istringstream ss(input);
			std::getline(ss, year, ' ');
			std::getline(ss, make, ' ');
			std::getline(ss, model, '\n');
		
			if (test.search(stoi(year), make, model) != nullptr) {
				std::cout << "Enter the distance you will be traveling: ";
				std::cin >> distance;
				std::cout << "Enter the number of passengers: ";
				std::cin >> passengers;
			
				if (distance > 0 && passengers > 0) {
					test.setCarData(stoi(year), make, model, distance, passengers);
					done = true;
					test.printInfo();
				}
				else {
					std::cout << "Distance and passengers must be greater than 0" << std::endl;
				}
			}
			else {
				std::cout << "Invalid input" << std::endl;
		}
		}else
			std::cout << "Invalid input" << std::endl;
		
	}
	return 0;
}
