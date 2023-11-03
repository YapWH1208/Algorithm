cmake_minimum_required(VERSION 3.26)
project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algorithm BinarySearch.cpp MergeSort.cpp
        Main.cpp
        MergeSort.h
        BinarySearch.h
        QuickSort.cpp
        QuickSort.h
        Strassen.cpp
        Strassen.h
        RadixSort.cpp
        RadixSort.h
        BubbleSort.cpp
        BubbleSort.h
        SelectionSort.cpp
        SelectionSort.h)
