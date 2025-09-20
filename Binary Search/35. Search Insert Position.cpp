#include <iostream>     
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;  // Prevents overflow

            if (nums[mid] == target) {
                return mid; // target found
            } 
            else if (nums[mid] > target) {
                high = mid - 1; // search left half
            } 
            else {
                low = mid + 1; // search right half
            }
        }

        // If not found, 'low' is the correct insert position
        return low;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int result = sol.searchInsert(nums, target);
    cout << "Insert position of " << target << " is: " << result << endl;

    target = 2;
    result = sol.searchInsert(nums, target);
    cout << "Insert position of " << target << " is: " << result << endl;

    target = 7;
    result = sol.searchInsert(nums, target);
    cout << "Insert position of " << target << " is: " << result << endl;

    target = 0;
    result = sol.searchInsert(nums, target);
    cout << "Insert position of " << target << " is: " << result << endl;

    return 0;
}
