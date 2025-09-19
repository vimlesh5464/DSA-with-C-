#include <iostream>
#include<vector>
using namespace std;

// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            // If current number is negative, swap max and min
            if (curr < 0) {
                swap(maxSoFar, minSoFar);
            }

            maxSoFar = max(curr, curr * maxSoFar);
            minSoFar = min(curr, curr * minSoFar);

            result = max(result, maxSoFar);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum product subarray = " << sol.maxProduct(nums) << endl;

    vector<int> nums2 = {-2, 0, -1};
    cout << "Maximum product subarray = " << sol.maxProduct(nums2) << endl;

    return 0;
}
