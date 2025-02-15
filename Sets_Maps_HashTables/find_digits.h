#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

std::string findTheDigits(std::string x, std::string y) {
	
	std::string result = "";
	std::map<char, int> yDigits;
	std::map<char, int> xDigits;

	// create map with digits as the key, and int set to 1 as default
	for (int i = 0; i < y.size(); i++) {
		
		// increment value if key is found
		if (yDigits.find(y[i]) != yDigits.end()) {
			yDigits[y[i]]++;
		}
		else
			yDigits[y[i]] = 1;
	}

	// create same map for xDigits
	for (int i = 0; i < x.size(); i++) {
		if (xDigits.find(x[i]) != xDigits.end()) {
			xDigits[x[i]]++;
		}
		else
			xDigits[x[i]] = 1;
	}

	// iterate through xDigits checking if key in xDigits is in yDigits
	for (auto it = xDigits.begin(); it != xDigits.end(); it++) {
		// if key is found in yDigits, subtract value from yDigits
		if (yDigits.find(it->first) != yDigits.end()) {
			yDigits[it->first] -= it->second;
			// if value is less than or equal to 0, erase key from yDigits
			if (yDigits[it->first] <= 0)
				yDigits.erase(it->first);
		}
		
	}

	// iterate through yDigits
	for (auto it = yDigits.begin(); it != yDigits.end(); it++) {
		// append key to result value number of times
		for(int i = 0; i < it->second; i++)
			result += it->first;
	}

	return result;
}
