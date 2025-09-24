#include <iostream>     
#include<vector>
using namespace std;

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
