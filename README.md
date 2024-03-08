# Description
This program is intended to demonstrate basic usage of multithreading on Linux OS using pthreads.
It simply takes in command-line arguments which are parsed and analyzed by the application.
It will calculate the average, maximum, minimum, median, and standard deviation of these numbers in separate threads and ouput the values to the user in the command line.

This program was created and submitted as part of an assignment for CPSC 351 Operating Systems Concepts in 2024.

# Building
This program uses CMake to build binary executibles.
Make sure that CMake is installed and run the following commands to build:
> cmake -S . -B build               
> cmake --build build

# Credits
Julian Matuszewski
julianmatuszewski@csu.fullerton.edu

# Copyright
This program is covered under the MIT License found in LICENSE file.
All rights reserved.
