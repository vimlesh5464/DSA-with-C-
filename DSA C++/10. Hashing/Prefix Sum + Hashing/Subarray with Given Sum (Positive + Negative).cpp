// Given an array arr[] of size N containing both positive and negative integers and an integer K, find the first subarray (a contiguous part of the array) that adds up to exactly K.

//     Input: arr = [10, 2, -2, -20, 10], K = -10
//     Output: Subarray found between indexes 0 and 3 (Explanation:
//     )

// The Approach: Hash Map (Prefix Sum)
// Since the array has negative numbers, a sliding window won't work. Instead, we use the Prefix Sum property:

//     Maintain a running sum (curr_sum) as you traverse the array.
//     If curr_sum == K at any point, the subarray starts from index 0.
//     If curr_sum - K has been seen before in our Hash Map, it means the elements between that previous occurrence and the current index sum up to K.
//     Store each curr_sum in a map with its index so we can retrieve it later.

// Time Complexity:
// — We traverse the array once; map lookups are
// on average.
// Space Complexity:
// — In the worst case, we store every prefix sum in the map.
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void findSubarray(vector<int>& arr, int K) {
    int n = arr.size();
    unordered_map<int, int> map;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];

        // Case 1: Subarray starts from index 0
        if (curr_sum == K) {
            cout << "Subarray found between indexes 0 to " << i << endl;
            return;
        }

        // Case 2: Check if (curr_sum - K) exists in the map
        if (map.find(curr_sum - K) != map.end()) {
            cout << "Subarray found between indexes " 
                 << map[curr_sum - K] + 1 << " to " << i << endl;
            return;
        }

        // Store curr_sum with its index if not already present
        if (map.find(curr_sum) == map.end()) {
            map[curr_sum] = i;
        }
    }

    cout << "No subarray with given sum exists" << endl;
}

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int K = -10;
    findSubarray(arr, K);
    return 0;
}