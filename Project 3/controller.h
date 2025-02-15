#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <cmath>
#include "carData.h"

class EmmissionsData {
public:

	/* Constructors */
	EmmissionsData();
	EmmissionsData(int year, std::string make, std::string model, int distance, int passengers);
	void getCarData(std::vector<Car>& cars);

	/* Mutators */
	void setCarData(int year, std::string make, std::string model, int distance, int passengers);

	/* Getters */
	double getPlaneEmissions() const;
	double getCarEmissions() const;
	Car* getChosenCar() const;
	void printInfo();
	Car* search(int year, std::string make, std::string model);

	/* Sort Functions */
	void sortCars(std::vector<Car>& cars);
	void mergeSort(std::vector<Car>& cars, int left, int right);
	void merge(std::vector<Car>& cars, int left, int mid, int right);
	void quickSort(std::vector<Car>& cars, int low, int high);
	int partition(std::vector<Car>& cars, int low, int high);

private:

	std::vector<Car> cars = std::vector<Car>();
	// emmssions output in grams per gallon of gas burned
	const int emissionsPerGallon = 8887;

	/* Given Variables */
	int distance;
	int passengers;
	int year;
	std::string make;
	std::string model;

	/* Generated Variables */
	Car* chosenCar;
	double carEmissions;
	double planeEmissions;
};