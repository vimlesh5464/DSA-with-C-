// Given an array of integers arr[]. You have to find the Inversion Count of the array. 
// Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

// Examples:

// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

// Input: arr[] = [2, 3, 4, 5, 6]
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.

// Input: arr[] = [10, 10, 10]
// Output: 0
// Explanation: As all the elements of array are same, so there is no inversion count.

// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104


#include<iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    long long merge(vector<int> &arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left;
        int j = mid + 1;
        long long inv = 0;

        while(i <= mid && j <= right) {
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                inv += (mid - i + 1);  // Count inversions
            }
        }

        while(i <= mid)
            temp.push_back(arr[i++]);

        while(j <= right)
            temp.push_back(arr[j++]);

        for(int k = left; k <= right; k++)
            arr[k] = temp[k - left];

        return inv;
    }

    long long mergeSort(vector<int> &arr, int left, int right) {
        long long inv = 0;
        if(left < right) {
            int mid = (left + right) / 2;
            inv += mergeSort(arr, left, mid);
            inv += mergeSort(arr, mid + 1, right);
            inv += merge(arr, left, mid, right);
        }
        return inv;
    }

    long long inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};