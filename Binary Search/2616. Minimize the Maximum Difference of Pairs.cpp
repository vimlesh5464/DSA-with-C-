#include <iostream>     
#include<vector>
using namespace std;

class Solution {
public:
    // Helper function: checks if we can form at least 'p' pairs 
    // with difference <= maxDiff
    bool isValid(vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        for (int i = 1; i < nums.size();) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i += 2; // use both nums[i-1] and nums[i]
            } else {
                i += 1; // skip one
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums.front();
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValid(nums, p, mid)) {
                result = mid;      // valid → try smaller maxDiff
                high = mid - 1;
            } else {
                low = mid + 1;     // not valid → need bigger maxDiff
            }
        }

        return result;
    }
};

// Driver code for testing
int main() {
    Solution sol;
    
    vector<int> nums1 = {10, 1, 2, 7, 1, 3};
    int p1 = 2;
    cout << sol.minimizeMax(nums1, p1) << endl; // Output: 1

    vector<int> nums2 = {4, 2, 1, 2};
    int p2 = 1;
    cout << sol.minimizeMax(nums2, p2) << endl; // Output: 0

    return 0;
}
