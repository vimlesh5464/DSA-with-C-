// Given an array arr of N elements,  A majority element in an array arr of size N is an element that appears more than N/2 times in the array. The task is to write a function say isMajority() that takes an array (arr[] ), array’s size (n) and a number to be searched (x) as parameters and returns true if x is a majority element (present more than n/2 times).

// Examples: 

// Input: arr[] = {1, 2, 3, 3, 3, 3, 10}, x = 3
// Output: True (x appears more than n/2 times in the given array)
// Input: arr[] = {1, 1, 2, 4, 4, 4, 6, 6}, x = 4
// Output: False (x doesn't appear more than n/2 times in the given array)
// Input: arr[] = {1, 1, 1, 2, 2}, x = 1
// Output: True (x appears more than n/2 times in the given array)
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
  public:
      bool isMajority(int arr[], int n, int x) {
          int count = 0;
  
          for(int i = 0; i < n; i++) {
              if(arr[i] == x) {
                  count++;
              }
          }
  
          return count > n / 2;
      }
  };

bool isMajorityElement(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;

    // Binary search to find the first occurrence of target
    while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }

    // Check if target appears more than n/2 times
    if (low < n && nums[low] == target && (low + n / 2 < n) && nums[low + n / 2] == target)
        return true;

    return false;
}

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter target element: ";
    cin >> target;

    if (isMajorityElement(nums, target))
        cout << target << " is a majority element." << endl;
    else
        cout << target << " is not a majority element." << endl;

    return 0;
}
