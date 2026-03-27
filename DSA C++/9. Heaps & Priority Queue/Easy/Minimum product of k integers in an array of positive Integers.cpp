#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minProduct(vector<int> &arr, int k) {
    
    // sort the array
    sort(arr.begin(), arr.end());

    // to store the result
    int res = 1;

    // find product of first k elements
    for(int i = 0; i < k; i++) {
        res *= arr[i];
    }

    return res;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minProduct(vector<int>& arr, int k) {
    
    // Step 1: Create a max heap with first k elements
    priority_queue<int> maxHeap;
    for (int i = 0; i < k; ++i) {
        maxHeap.push(arr[i]);
    }
    
    // Step 2: Process remaining elements
    for (int i = k; i < arr.size(); ++i) {
        if (arr[i] < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    
    // Step 3: Multiply elements in heap
    int product = 1;
    while (!maxHeap.empty()) {
        product *= maxHeap.top();
        maxHeap.pop();
    }
    
    return product;
}



int main() {
    vector<int> arr = { 198, 76, 544, 123, 154, 675 };
    int k = 2;
    cout << minProduct(arr, k);
    return 0;
}