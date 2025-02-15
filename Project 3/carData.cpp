#include "carData.h"

Car::Car() {
	this->year = 0;
	this->make = "";
	this->model = "";
	this->avgMPG = 0;
	this->cityMPG = 0;
	this->highwayMPG = 0;
}

Car::Car(int year, std::string make, std::string model, int cityMPG, int highwayMPG) {
	this->year = year;
	this->make = make;
	this->model = model;
	this->cityMPG = cityMPG;
	this->highwayMPG = highwayMPG;
	this->avgMPG = (cityMPG + highwayMPG) / 2;
}

Car& Car::operator=(const Car& other) {
	if(this == &other)
		return *this;

	this->year = other.year;
	this->make = other.make;
	this->model = other.model;
	this->avgMPG = other.avgMPG;
	this->cityMPG = other.cityMPG;
	this->highwayMPG = other.highwayMPG;

	return *this;
}

bool Car::operator==(const Car& other) {
	if (this->year == other.year && this->make.compare(other.make) == 0 &&
		this->model.compare(other.model) == 0 && this->avgMPG == other.avgMPG
		&& this->cityMPG == other.cityMPG && this->highwayMPG == other.highwayMPG) {
		return true;
	}
	return false;
}

bool Car::operator<(const Car& other) {
	// compare make, then model, then year, then avgMPG, then cityMPG, then highwayMPG
	// if all are equal, order doesn't matter
	if (this->make.compare(other.make) < 0) {
		return true;
	}
	else if (this->make.compare(other.make) == 0) {
		if (this->model.compare(other.model) < 0) {
			return true;
		}
		else if (this->model.compare(other.model) == 0) {
			if (this->year < other.year) {
				return true;
			}
			else if (this->year == other.year) {
				if (this->avgMPG < other.avgMPG) {
					return true;
				}
				else if (this->avgMPG == other.avgMPG) {
					if (this->cityMPG < other.cityMPG) {
						return true;
					}
					else if (this->cityMPG == other.cityMPG) {
						if (this->highwayMPG < other.highwayMPG) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool Car::operator>(const Car& other) {
	// compare make, then model, then year, then avgMPG, then cityMPG, then highwayMPG
	// if all are equal, order doesn't matter
	if (this->make.compare(other.make) > 0) {
		return true;
	}
	else if (this->make.compare(other.make) == 0) {
		if (this->model.compare(other.model) > 0) {
			return true;
		}
		else if (this->model.compare(other.model) == 0) {
			if (this->year > other.year) {
				return true;
			}
			else if (this->year == other.year) {
				if (this->avgMPG > other.avgMPG) {
					return true;
				}
				else if (this->avgMPG == other.avgMPG) {
					if (this->cityMPG > other.cityMPG) {
						return true;
					}
					else if (this->cityMPG == other.cityMPG) {
						if (this->highwayMPG > other.highwayMPG) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

int Car::getYear() const {
	return this->year;
}

std::string Car::getMake() const {
	return this->make;
}

std::string Car::getModel() const {
	return this->model;
}

int Car::getCityMPG() const {
	return this->cityMPG;
}

int Car::getHighwayMPG() const {
	return this->highwayMPG;
}

int Car::getAvgMPG() const {
	return this->avgMPG;
}

std::string Car::getSearchString() {
	return std::to_string(this->year) + this->make + this->model;
}
