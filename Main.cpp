#include <vector>
#include <iostream>
#include "MergeSort.h"
#include "BinarySearch.h"
#include "QuickSort.h"

using namespace std;

int main(){
    vector<int> arr = {5,1,9,4,6,8,4,2,7,9,3};
    quickSort(arr,0,11);
    //mergeSort(arr,0,11);
    //int pos = binarySearch(arr, 7) + 1;

    for(int i : arr){
        cout<< i << " ";
    }
    cout << endl;

    //cout << pos << endl;

    return 0;
}