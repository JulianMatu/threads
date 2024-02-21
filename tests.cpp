// tests.cpp
#include "tests.hpp"

// global variables
double average_value = 0;
double maximum_value = 0;
double minimum_value = 0;
double median_value = 0;
double sd_value = 0;

// test function
bool startTests(const std::vector<int>& array) {
	// initialize all 5 worker threads
	pthread_t thread1, thread2, thread3, thread4, thread5;

	// start all worker threads
	pthread_create(&thread1, NULL, *first_thread, (void*)&array);
	pthread_create(&thread2, NULL, *second_thread, (void*)&array);
	pthread_create(&thread3, NULL, *third_thread, (void*)&array);
	pthread_create(&thread4, NULL, *fourth_thread, (void*)&array);
	pthread_create(&thread5, NULL, *fifth_thread, (void*)&array);
	
	// wait for threads to finish before continuing
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	pthread_join(thread5, NULL);

	// print out calculated results
	printf("Average value: %f\n", average_value);
	printf("Maximum value: %f\n", maximum_value);
	printf("Minimum value: %f\n", minimum_value);
	printf("Median value: %f\n", median_value);
	printf("Standard deviation: %f\n", sd_value);
		
	// check all answers without multithreading
	if (average_value != average(array) ||
		maximum_value != maximum(array) ||
		minimum_value != minimum(array) ||
		median_value != median(array) ||
		sd_value != standard_deviation(array)) {
		return false;
	}

	// true means all tests passed
	return true;
}

// pthreads functions
void* first_thread(void* arg) {
	// cast void* to vector*
	std::vector<int>* input = static_cast<std::vector<int>*>(arg);

	average_value = average(*input);

	return NULL;
};
void* second_thread(void* arg) {
	// cast void* to vector*
	std::vector<int>* input = static_cast<std::vector<int>*>(arg);

	maximum_value = maximum(*input);

	return NULL;
};
void* third_thread(void* arg) {
	// cast void* to vector*
	std::vector<int>* input = static_cast<std::vector<int>*>(arg);

	minimum_value = minimum(*input);

	return NULL;
};
void* fourth_thread(void* arg) {
	// cast void* to vector*
	std::vector<int>* input = static_cast<std::vector<int>*>(arg);

	median_value = median(*input);

	return NULL;
};
void* fifth_thread(void* arg) {
	// cast void* to vector*
	std::vector<int>* input = static_cast<std::vector<int>*>(arg);

	sd_value = standard_deviation(*input);

	return NULL;
};