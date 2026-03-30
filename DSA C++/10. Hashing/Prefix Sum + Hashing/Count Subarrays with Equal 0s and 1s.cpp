// Given an array arr[] of size n containing 0 and 1 only. The problem is to count the subarrays having an equal number of 0's and 1's.

// Examples:  

//     Input: arr[] = {1, 0, 0, 1, 0, 1, 1}
//     Output: 8
//     Explanation: The index range for the 8 sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), (4, 5)(2, 5), (0, 5), (1, 6)


//     Input: arr = { 1, 0, 0, 1, 1, 0, 0, 1}
//     Output: 12


// C++ implementation to count subarrays with
// equal number of 1's and 0's
#include<unordered_map>
#include <iostream>
using namespace std;


// function to count subarrays with
// equal number of 1's and 0's
int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    // 'um' implemented as hash table to store
    // frequency of values obtained through
    // cumulative sum
    unordered_map<int, int> um;
    int curr_sum = 0;

    // Traverse original array and compute cumulative
    // sum and increase count by 1 for this sum
    // in 'um'. Adds '-1' when arr[i] == 0
    for (int i = 0; i < n; i++) {
        curr_sum += (arr[i] == 0) ? -1 : arr[i];
        um[curr_sum]++;
    }

    int count = 0;
    // traverse the hash table 'um'
    for (auto itr = um.begin(); itr != um.end(); itr++) {

        // If there are more than one prefix subarrays
        // with a particular sum
        if (itr->second > 1)
            count
                += ((itr->second * (itr->second - 1)) / 2);
    }

    // add the subarrays starting from 1st element and
    // have equal number of 1's and 0's
    if (um.find(0) != um.end())
        count += um[0];

    // required count of subarrays
    return count;
}

// Driver program to test above
int main()
{
    int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Count = "
         << countSubarrWithEqualZeroAndOne(arr, n);
    return 0;
}

// Time Complexity: O(N), where N is the length of the given array
// Auxiliary Space: O(N).

int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    unordered_map<int, int> mp;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        // Replacing 0's in array with -1
        if (arr[i] == 0)
            arr[i] = -1;

        sum += arr[i];

        // If sum = 0, it implies number of 0's and 1's are
        // equal from arr[0]..arr[i]
        if (sum == 0)
            count++;

        // if mp[sum] exists then add "frequency-1" to count
        if (mp[sum])
            count += mp[sum];

        // if frequency of "sum" is zero then we initialize
        // that frequency to 1 if its not 0, we increment it
        if (mp[sum] == 0)
            mp[sum] = 1;
        else
            mp[sum]++;
    }
    return count;
}

int main()
{
    int arr[] = { 1, 0, 0, 1, 0, 1, 1 };

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "count="
         << countSubarrWithEqualZeroAndOne(arr, n);
}