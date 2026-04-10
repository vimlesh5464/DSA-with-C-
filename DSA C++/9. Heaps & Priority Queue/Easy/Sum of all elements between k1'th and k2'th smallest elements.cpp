
// Given an array A[] of N positive integers and two positive integers K1 and K2. Find the sum of all elements between K1th and K2th smallest elements of the array. It may be assumed that (1 <= k1 < k2 <= n).

 

// Example 1:

// Input:
// N  = 7
// A[] = {20, 8, 22, 4, 12, 10, 14}
// K1 = 3, K2 = 6
// Output:
// 26
// Explanation:
// 3rd smallest element is 10
// 6th smallest element is 20
// Element between 10 and 20 
// 12,14. Their sum = 26.

 

// Example 2:

// Input
// N = 6
// A[] = {10, 2, 50, 12, 48, 13}
// K1= 2, K2 = 6
// Output:
// 73

 

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function sumBetweenTwoKth() which takes the array A[], its size N and two integers K1 and K2 as inputs and returns the sum of all the elements between K1th and K2th smallest elements.
 

// Expected Time Complexity: O(N. log(N))
// Expected Auxiliary Space: O(N)
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
