// tests.hpp
#pragma once

#include <stdio.h>
#include <memory>
#include <vector>
#include <pthread.h>
#include "mathfuncs.hpp"

// test function
bool startTests(const std::vector<int>& array);

// pthreads
void* first_thread(void* arg);
void* second_thread(void* arg);
void* third_thread(void* arg);
void* fourth_thread(void* arg);
void* fifth_thread(void* arg);