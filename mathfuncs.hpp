// mathfunctions.h
// Contains various math functions used by tests.cpp for testing threads
#pragma once

#include <vector>
#include <cmath>

// return the average of an integer vector
inline double average(const std::vector<int>& input) {
	double temp = 0;
	for (auto num : input) {
		temp += (double)num;
	}

	return temp / input.size();
}

// return the average of an integer vector
inline int maximum(const std::vector<int>& input) {
	int max = input[0];
	for (int num : input) {
		if (num >= max) max = num;
	}

	return max;
}

inline int minimum(const std::vector<int>& input) {
	int min = input[0];
	for (int num : input) {
		if (num <= min) min = num;
	}

	return min;
}

inline double median(const std::vector<int>& input) {

	// middle index, rounded down
	int mid = input.size() / 2;

	// if even
	if (input.size() % 2 == 0) {
		return (double)(input[mid] + input[mid + 1]) / 2;
	}

	// if odd
	return input[mid];
}

inline double standard_deviation(const std::vector<int>& input) {
	double variance;
	double sd;
	double sds = 0;
	int size = input.size();
	double mean = average(input);

	// find the sum of differences squared between the mean and each value
	for (int num : input) {
		double num_double = (double)num;
		double diff = num_double - mean;
		sds += pow(diff, 2);
	}

	// divide sum of differences squared by the size of array
	variance = sds / size;

	// square root the variance to get the standard deviation
	sd = sqrt(variance);

	return sd;
}