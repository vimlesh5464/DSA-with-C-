#include <vector>
#include <iostream>
using namespace std;

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

            // Handle duplicates (worst-case O(n))
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    int n, target;

    // Input size of array
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    cout << "Enter " << n << " elements of the rotated sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Input target
    cout << "Enter the target to search: ";
    cin >> target;

    // Search and output
    if (s.search(nums, target)) {
        cout << "Target " << target << " is present in the array." << std::endl;
    } else {
        cout << "Target " << target << " is NOT present in the array." << std::endl;
    }

    return 0;
}
