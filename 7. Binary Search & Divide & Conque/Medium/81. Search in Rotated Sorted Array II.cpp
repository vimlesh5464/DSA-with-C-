#include <vector>
#include <iostream>

class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // ⚠️ Case 1: Handle Duplicates (Worst-case O(n) scenario)
            // If the values at low, mid, and high are all the same,
            // we cannot determine which half is sorted. Safest action is to shrink the range.
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Case 2: Left half is Sorted (nums[low] <= nums[mid])
            if (nums[low] <= nums[mid]) {
                // Check if the target is within the sorted left half range
                if (nums[low] <= target && target < nums[mid]) {
                    // Target is in the left half, discard the right half
                    high = mid - 1;
                } else {
                    // Target is NOT in the left half, search the right half
                    low = mid + 1;
                }
            }

            // Case 3: Right half is Sorted (nums[low] > nums[mid])
            else { 
                // Check if the target is within the sorted right half range
                if (nums[mid] < target && target <= nums[high]) {
                    // Target is in the right half, discard the left half
                    low = mid + 1;
                } else {
                    // Target is NOT in the right half, search the left half
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};


// Example Usage (for testing purposes):
int main() {
    Solution s;
    std::vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    std::cout << "Target 0 in nums1: " << (s.search(nums1, target1) ? "True" : "False") << std::endl; // Output: True

    std::vector<int> nums2 = {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;
    std::cout << "Target 3 in nums2: " << (s.search(nums2, target2) ? "True" : "False") << std::endl; // Output: False

    std::vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1}; // Worst case with duplicates
    int target3 = 2;
    std::cout << "Target 2 in nums3: " << (s.search(nums3, target3) ? "True" : "False") << std::endl; // Output: True

    return 0;
}
