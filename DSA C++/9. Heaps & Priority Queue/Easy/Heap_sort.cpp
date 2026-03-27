#include<iostream>
#include<vector>
using namespace std;

void heapify(int i, vector<int> &arr, int n){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(largest, arr, n);
    }
}

void heap_sort(vector<int> &arr){
    int n = arr.size();

    // Build max heap (safe loop)
    for(int i = n/2 - 1; i >= 0; --i){
        heapify(i, arr, n);
        if(i == 0) break;   // <-- PREVENTS i from becoming -1
    }

    // Extract elements from heap
    for(int i = n - 1; i >= 0; --i){
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}

int main(){
    vector<int> arr = {5, 3, 8, 4, 2, 7};
    heap_sort(arr);

    for(int x : arr) cout << x << " ";
    return 0;
}
