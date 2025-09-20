#include <iostream>     
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); // size of the array

        // Edge cases
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;

            // If nums[mid] is the single element
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            // We are in the left half
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1; // Eliminate left half
            } else {
                high = mid - 1; // Eliminate right half
            }
        }

        // Should never reach here if input is valid
        return -1;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums1 = {1,1,2,3,3,4,4,8,8};
    vector<int> nums2 = {3,3,7,7,10,11,11};

    cout << "Single element in nums1: " << sol.singleNonDuplicate(nums1) << endl;
    cout << "Single element in nums2: " << sol.singleNonDuplicate(nums2) << endl;

    return 0;
}
