

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int sumBetweenK1K2(vector<int> &arr, int k1, int k2) {
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    int sum = 0;

    // Pop first k1 elements
    for (int i = 0; i < k1; i++) pq.pop();

    // Pop next (k2 - k1 - 1) elements and add to sum
    for (int i = 0; i < k2 - k1 - 1; i++) {
        sum += pq.top();
        pq.pop();
    }

    return sum;
}

int main() {
    vector<int> arr = {1, 3, 12, 5, 15, 11};
    int k1 = 3, k2 = 6;
    cout << sumBetweenK1K2(arr, k1, k2) << endl;  // Output: 23
}
