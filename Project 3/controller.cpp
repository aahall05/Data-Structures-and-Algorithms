#include "controller.h"


EmmissionsData::EmmissionsData() {
	// initialize given variables
	this->year = 0;
	this->make = "";
	this->model = "";
	this->distance = 0;
	this->passengers = 0;
	// get car data
	getCarData(this->cars);
	// sort car data
	sortCars(this->cars);
}

EmmissionsData::EmmissionsData(int year, std::string make, std::string model, int distance, int passengers) {
	this->year = year;
	this->make = make;
	this->model = model;
	this->distance = distance;
	this->passengers = passengers;

	getCarData(this->cars);
	sortCars(this->cars);
	// search for car
	this->chosenCar = search(year, make, model);
}

void EmmissionsData::getCarData(std::vector<Car>& cars) {
	
	std::string filename = "carsWithRandom3.csv";
	std::ifstream file(filename);
	std::string line;

	// skip header line
	std::getline(file, line);

	// read each line from the file
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string item;
		int count = 0;
		std::string make, model, year, cityMPG, highwayMPG;

		// split the line by commas
		while (std::getline(ss, item, ',')) {
			count++;
			// get the number without quotes
			if (count == 9)
				cityMPG = item.substr(1, item.size() - 2); 
			if (count == 11)
				highwayMPG = item.substr(1, item.size() - 2);
			if (count == 13) {
				// find the first and second space in the string
				size_t firstSpace = item.find(' ');
				size_t secondSpace = item.find(' ', firstSpace + 1);
				// get the model substring, without the backslash at the end
				model = item.substr(secondSpace + 1, item.size() - (secondSpace + 2));
			}
			if (count == 14)
				make = item.substr(1, item.size() - 2);
			if (count == 16)
				year = item.substr(1, item.size() - 2);
		}
		// add new car to cars vector
		cars.push_back(Car(std::stoi(year), make, model, std::stoi(cityMPG), std::stoi(highwayMPG)));
	}
}

void EmmissionsData::setCarData(int year, std::string make, std::string model, int distance, int passengers) {
	this->year = year;
	this->make = make;
	this->model = model;
	this->distance = distance;
	this->passengers = passengers;
	this->chosenCar = search(year, make, model);
}

double EmmissionsData::getPlaneEmissions() const {
	/*
		* the estimated emissions for a plane is 162 grams of CO2 per passenger mile
		* https://www.carbonindependent.org/22.html
	*/
	return std::round(162.0 * this->distance * 100.0) / 100.0;
}

double EmmissionsData::getCarEmissions() const {
	/*
		* since the number I found was based on the g of CO2 produced by a gallon
		  of gas, this returns the emissions produced by the CAR for the trip
		  without considering the change in emissions due to the number of passengers.
		  While this is not the most accurate way to calculate emissions, it is a good
		  estimate based on what I found.
		* assuming negligible change in emissions due to passengers, g of CO2 per
		  passenger would divide this total by the number of passengers
		* (distance / mpg) is gallons of gas used for the trip
		* multiplied by a constant found on EPA website 
		https://www.epa.gov/greenvehicles/greenhouse-gas-emissions-typical-passenger-vehicle
	*/
	return std::round(((static_cast<double>(distance) / this->chosenCar->getAvgMPG()) * this->emissionsPerGallon) * 100.0) / 100.0;
}

Car* EmmissionsData::getChosenCar() const {
	return this->chosenCar;
}

void EmmissionsData::printInfo() {
	std::cout << std::endl << "Results" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "Distance: " << this->distance << std::endl;
	std::cout << "Passengers: " << this->passengers << std::endl;
	std::cout << "Vehicle: " << this->year << " " << this->make << " " << this->model << std::endl;
	std::cout << "Total Car Emissions: " << getCarEmissions() << "g of CO2" << std::endl;
	std::cout << "Car Emissions per Passenger: " << getCarEmissions() / this->passengers << "g of CO2" << std::endl;
	// since the plane emissions returned are per passenger, we multiply by the number of passengers to get total emissions
	std::cout << "Total Plane Emissions: " << getPlaneEmissions() * this->passengers << "g of CO2" << std::endl;
	std::cout << "Plane Emissions per Passenger: " << getPlaneEmissions() << "g of CO2" << std::endl;
}

void EmmissionsData::sortCars(std::vector<Car>& cars) {
	
	// merge sort will sort in place, so we need a copy for Quick sort
	std::vector<Car> carsCopy = cars;
	
	// time and run merge sort
	auto startMergeSort = std::chrono::high_resolution_clock::now();

	size_t mid = cars.size() / 2;
	mergeSort(cars, 0, static_cast<int>(cars.size()) - 1);

    auto endMergeSort = std::chrono::high_resolution_clock::now();
    auto mergeSortTime = endMergeSort - startMergeSort;
    std::cout << "Merge Sort Time: " << mergeSortTime.count() << " nanoseconds (" << mergeSortTime.count() / 1e9 << " seconds)" << std::endl;

	// time and run Quick sort
	auto startQuickSort = std::chrono::high_resolution_clock::now();

	quickSort(carsCopy, 0, static_cast<int>(cars.size()) - 1);

	auto endQuickSort = std::chrono::high_resolution_clock::now();
	auto quickSortTime = endQuickSort - startQuickSort;
	std::cout << "Quick Sort Time: " << quickSortTime.count() << " nanoseconds (" << quickSortTime.count() / 1e9 << " seconds)" << std::endl;
}

void EmmissionsData::mergeSort(std::vector<Car>& cars, int left, int right) {
	
	if(left < right){
		int mid = left + (right - left) / 2;
		mergeSort(cars, left, mid);
		mergeSort(cars, mid + 1, right);
		merge(cars, left, mid, right);
	}
}

void EmmissionsData::merge(std::vector<Car>& cars, int left, int mid, int right) {
	// sort order is specified in the overloaded < and > operators in carData.cpp
	
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<Car> X(n1);
	std::vector<Car> Y(n2);

	// copy two halves into X and Y
	for (int i = 0; i < n1; i++) 
		X[i] = cars[left + i];
	
	for (int j = 0; j < n2; j++) 
		Y[j] = cars[mid + 1 + j];
	
	// merge the two halves
	int i, j, k;
	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2) {
		// compare
		if (X[i] < Y[j]) {
			cars[k] = X[i];
			i++;
		}
		else {
			cars[k] = Y[j];
			j++;
		}
		k++;
	}

	// Copy remaining elements of X, if any
	while (i < n1) {
		cars[k] = X[i];
		i++;
		k++;
	}

	// Copy remaining elements of Y, if any
	while (j < n2) {
		cars[k] = Y[j];
		j++;
		k++;
	}
}

void EmmissionsData::quickSort(std::vector<Car>& cars, int low, int high) {
	
	if (low < high) {
		int pivotIndex = partition(cars, low, high);

		quickSort(cars, low, pivotIndex - 1);
		quickSort(cars, pivotIndex + 1, high);
	}

}

int EmmissionsData::partition(std::vector<Car>& cars, int low, int high) {
	// use last element as pivot
	int pivot = high;
	int left = low;
	int right = high - 1;

	while(true) {
		// find first element greater than pivot
		while (left <= right && cars[left] < cars[pivot])
			left++;
		// find first element less than pivot
		while (right >= left && cars[right] > cars[pivot])
			right--;
		// swap elements
		if (left >= right)
			break;
		std::swap(cars[left], cars[right]);
		left++;
		right--;
	}
	// swap pivot and left element
	std::swap(cars[left], cars[pivot]);
	return left;
}

Car* EmmissionsData::search(int year, std::string make, std::string model) {
	std::string target = std::to_string(year) + make + model;
	// Car* cars = this->cars;
	Car* result = nullptr;

	// convert target to lowercase so case doesn't matter when searching
	std::transform(target.begin(), target.end(), target.begin(), ::tolower);

	// using getSearchString() find target
	for (int i = 0; i < this->cars.size(); i++) {
		std::string temp = this->cars[i].getSearchString();
		std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

		if (temp.compare(target) == 0)
			result = &cars[i];
	}

	if(result == nullptr)
		std::cout << "Car not found" << std::endl;
	
	return result;
}
