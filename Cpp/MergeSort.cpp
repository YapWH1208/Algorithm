#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;

    int *temp = new(nothrow) int[right - left + 1];

    if (!temp) {
        cout << "ERROR" << endl;
        return;
    }

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for(i=left, k=0; i<=right; i++,k++)arr[i]=temp[k];

    delete []temp;
}
void mergeSort(vector<int> &arr, int left, int right){
    if(left < right){
        int mid = left - (left - right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr,left,mid,right);
    }
}