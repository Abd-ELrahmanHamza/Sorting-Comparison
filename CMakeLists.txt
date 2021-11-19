cmake_minimum_required(VERSION 3.20)
project(Solution)

set(CMAKE_CXX_STANDARD 14)

add_executable(Solution
        selectionSort.h insertionSort.h stress_test.cpp mergeSort.h quickSort.h sort.cpp readPrintFile.h hybridSort.h)
