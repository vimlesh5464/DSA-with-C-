// Given an array arr[] of distinct integers of size n and a value sum, 
//the task is to find the count of triplets (i, j, k), having (i<j<k) with the 
//sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.

// Examples :

// Input: n = 4, sum = 2, arr[] = {-2, 0, 1, 3}
// Output:  2
// Explanation: Below are triplets with sum less than 2 (-2, 0, 1) and (-2, 0, 3). 

// Input: n = 5, sum = 12, arr[] = {5, 1, 3, 4, 7}
// Output: 4
// Explanation: Below are triplets with sum less than 12 (1, 3, 4), (5, 1, 3), (1, 3, 7) and (5, 1, 4).

// Constraints:
// 3 ≤ N ≤ 103
// -103 ≤ arr[i] ≤ 103
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        long long count = 0;

        // Sort the array
        sort(arr, arr + n);

        for(int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                long long currSum = arr[i] + arr[left] + arr[right];

                if(currSum < sum) {
                    // All triplets from left to right with arr[i] are valid
                    count += (right - left);
                    left++;
                } else {
                    right--;
                }
            }
        }

        return count;
    }
};

int main() {
    int n;
    long long sum;
    
    cout << "Enter size of array: ";
    cin >> n;

    long long arr[n];
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> sum;

    Solution sol;
    long long result = sol.countTriplets(n, sum, arr);

    cout << "Number of triplets with sum less than " << sum << " is: " << result << endl;

    return 0;
}
