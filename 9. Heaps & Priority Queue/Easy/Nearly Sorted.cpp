

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void nearlySorted(vector<int> &arr, int k) {

    int n = arr.size();

    // creating a min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // pushing first k elements in pq
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    int i;

    for (i = k; i < n; i++) {

        pq.push(arr[i]);

        // size becomes k+1 so pop it
        // and add minimum element in (i-k) index
        arr[i - k] = pq.top();
        pq.pop();
    }

    // puting remaining elements in array
    while (!pq.empty()) {
        arr[i - k] = pq.top();
        pq.pop();
        i++;
    }
}

int main() {
    vector<int> arr = {2, 3, 1, 4};
    int k = 2;
    nearlySorted(arr, k);
    for (int x : arr)
        cout << x << ' ';
    return 0;
}