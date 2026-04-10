// Given an array arr of positive integers, return the minimum possible product of any k elements from the array. Return the result modulo 1e9 + 7.

// Examples:

// Input: arr[] = [1, 2, 3, 4, 5], k = 2
// Output: 2
// Explanation: We will get the minimum product after multiplying 1 and 2 that is 2. So, the answer is 2.

// Input: arr[] = [9, 10, 8], k = 3
// Output: 720
// Explanation: We have to multiply all the numbers.

// Constraints:
// 1 ≤ k, arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 105
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int minProduct(vector<int> &arr, int k) {
        const long long MOD = 1e9 + 7;

        sort(arr.begin(), arr.end());

        long long res = 1;

        for (int i = 0; i < k; i++) {
            res = (res * 1LL * arr[i]) % MOD; // ✅ safe multiplication
        }

        return (int)res;
    }
};


class Solution {
public:
    int minProduct(vector<int> &arr, int k) {
        const long long MOD = 1e9 + 7;

        // Max heap to keep k smallest elements
        priority_queue<int> maxHeap;

        for (int x : arr) {
            maxHeap.push(x);

            if (maxHeap.size() > k) {
                maxHeap.pop(); // remove largest
            }
        }

        long long product = 1;

        while (!maxHeap.empty()) {
            product = (product * 1LL * maxHeap.top()) % MOD;
            maxHeap.pop();
        }

        return (int)product;
    }
};


int main() {
  Solution s;
    vector<int> arr = { 198, 76, 544, 123, 154, 675 };
    int k = 2;
    cout << s.minProduct(arr, k);
    return 0;
}