cmake_minimum_required(VERSION 3.26)
project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algorithm BinarySearch.cpp MergeSort.cpp
        Main.cpp
        QuickSort.cpp
        Strassen.cpp
        RadixSort.cpp
        BubbleSort.cpp
        SelectionSort.cpp
        Dijkstra.c
        BFS.c
        DFS.c
        Matrix.h
        Sort.h
        Search.h
        Graph.h)
