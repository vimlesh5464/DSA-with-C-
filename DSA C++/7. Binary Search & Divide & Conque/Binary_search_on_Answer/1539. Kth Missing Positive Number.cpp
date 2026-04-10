// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from this array.

 

// Example 1:

// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

// Example 2:

// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

 

// Constraints:

//     1 <= arr.length <= 1000
//     1 <= arr[i] <= 1000
//     1 <= k <= 1000
//     arr[i] < arr[j] for 1 <= i < j <= arr.length

#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      int findKthPositive(vector<int>& arr, int k) {
          int i = 0;      // pointer for array
          int num = 1;    // current number
  
          while(k > 0) {
              // if current number matches array element → skip
              if(i < arr.size() && arr[i] == num) {
                  i++;
              } else {
                  k--; // missing number found
                  if(k == 0) return num;
              }
              num++;
          }
  
          return num;
      }
  };
int findKthPositive(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int missing = arr[mid] - (mid + 1);

        if (missing < k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // kth missing number = k + high + 1
    return k + high + 1;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << findKthPositive(arr, k) << endl; // Output: 9
}
