#include <iostream>     
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; // avoid overflow

            if (nums[mid] == target) {
                return mid; // target found
            } 
            else if (nums[mid] < target) {
                left = mid + 1; // search right half
            } 
            else {
                right = mid - 1; // search left half
            }
        }

        return -1; // target not found
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int result = sol.search(nums, target);
    cout << "Index of " << target << " is: " << result << endl;

    return 0;
}
