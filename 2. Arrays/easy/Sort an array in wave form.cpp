// Given a sorted array arr[] of integers (in ascending order), rearrange the elements in-place to form a wave-like array.
// An array is said to be in wave form if it satisfies the following pattern: arr[0] ≥ arr[1] ≤ arr[2] ≥ arr[3] ≤ arr[4] ≥ ...
// In other words, every even-indexed element should be greater than or equal to its adjacent odd-indexed elements (if they exist).

// Note: The given array is sorted in ascending order, and modify the given array in-place without returning a new array.

//     Input: arr[] = [1, 2, 3, 4, 5]
//     Output: [2, 1, 4, 3, 5]
//     Explanation: Array elements after sorting it in the waveform are 2, 1, 4, 3, 5.

//     Input: arr[] = [2, 4, 7, 8, 9, 10]
//     Output: [4, 2, 8, 7, 10, 9]
//     Explanation: Array elements after sorting it in the waveform are 4, 2, 8, 7, 10, 9.
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//[Approach] Adjacent Pair Swapping Method

//Time Complexity: O(n), a single pass swaps adjacent pairs.
//Auxiliary Space: O(1), in-place swaps use no extra storage.
void sortInWave(vector<int> &arr){
    
    int n = arr.size();

    // swap adjacent elements to create 
    // wave pattern
    for (int i = 0; i < n - 1; i += 2){
        swap(arr[i], arr[i + 1]);
    }
}


int main(){
    
    vector<int> arr = {1, 2, 3, 4, 5};
    sortInWave(arr);
    for (int i=0; i<arr.size(); i++)
       cout << arr[i] << " ";
    return 0;
}