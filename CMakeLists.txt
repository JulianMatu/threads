# CMakeList.txt : CMake project for threads, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("threads")

# Packages
find_package( Threads )

# Add source to this project's executable.
add_executable (threads "threads.cpp" "threads.hpp" "tests.cpp" "tests.hpp" "mathfuncs.hpp")

# Target Lists
target_link_libraries( threads ${CMAKE_THREAD_LIBS_INIT} )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET threads PROPERTY CXX_STANDARD 20)
endif()