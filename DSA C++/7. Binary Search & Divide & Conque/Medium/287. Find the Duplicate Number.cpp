#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        int duplicate = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Count how many numbers are <= mid
            int count = 0;
            for (int num : nums) {
                if (num <= mid)
                    count++;
            }

            if (count > mid) {
                duplicate = mid;
                high = mid - 1;  // search left half
            } else {
                low = mid + 1;   // search right half
            }
        }

        return duplicate;
    }
};

// 🔹 Driver code
int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    Solution sol;
    cout << sol.findDuplicate(nums) << endl;  // Output: 2
    return 0;
}
