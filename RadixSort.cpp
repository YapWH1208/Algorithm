#include <iostream>
#include <vector>
#include "RadixSort.h"

using namespace std;

int getMax(vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(vector<int>& arr, int exp) {
    const int radix = 10; // Base 10 (decimal system)
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(radix, 0);

    // Count occurrences of digits in the input array
    for (int i = 0; i < n; ++i) {
        int digit = (arr[i] / exp) % radix;
        count[digit]++;
    }

    // Change count[i] so that count[i] contains the actual
    // position of this digit in output[]
    for (int i = 1; i < radix; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
        int digit = (arr[i] / exp) % radix;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to the input array so that arr[] now contains sorted numbers
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int max = getMax(arr);

    // Do counting sort for every digit. Note that
    // instead of passing digit number, exp is passed.
    // exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}