// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Example 3:

// Input: nums = [1], target = 0
// Output: -1

 

// Constraints:

//     1 <= nums.length <= 5000
//     -104 <= nums[i] <= 104
//     All values of nums are unique.
//     nums is an ascending array that is possibly rotated.
//     -104 <= target <= 104

 

#include <iostream>     
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // target in left half
                } else {
                    left = mid + 1;  // target in right half
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // target in right half
                } else {
                    right = mid - 1; // target in left half
                }
            }
        }

        return -1; // target not found
    }
};

int main() {
    Solution sol;
    int n, target;

    // Input size of array
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    cout << "Enter " << n << " elements of rotated sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Input target
    cout << "Enter target to search: ";
    cin >> target;

    int result = sol.search(nums, target);

    if (result != -1) {
        cout << "Index of " << target << " is: " << result << endl;
    } else {
        cout << target << " not found in the array." << endl;
    }

    return 0;
}

class Solution {
public:
    int searchHelper(vector<int>& nums, int si, int ei, int target) {
        if (si > ei) return -1;

        int mid = si + (ei - si) / 2;

        if (nums[mid] == target) return mid;

        // Check if left half is sorted
        if (nums[si] <= nums[mid]) {
            if (nums[si] <= target && target < nums[mid]) {
                return searchHelper(nums, si, mid - 1, target);
            } else {
                return searchHelper(nums, mid + 1, ei, target);
            }
        } 
        // Otherwise, right half must be sorted
        else {
            if (nums[mid] < target && target <= nums[ei]) {
                return searchHelper(nums, mid + 1, ei, target);
            } else {
                return searchHelper(nums, si, mid - 1, target);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return searchHelper(nums, 0, nums.size() - 1, target);
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = sol.search(nums, target);
    cout << "Index of " << target << " is: " << result << endl;

    target = 3;
    result = sol.search(nums, target);
    cout << "Index of " << target << " is: " << result << endl;

    return 0;
}
