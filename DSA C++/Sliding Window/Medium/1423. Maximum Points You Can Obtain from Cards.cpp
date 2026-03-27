#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lsum = 0, rsum = 0;
        int maxsum = 0;
        int n = nums.size();

        // Sum of first k elements
        for (int i = 0; i < k; i++) {
            lsum += nums[i];
        }
        maxsum = lsum;

        int index = n - 1;

        // Sliding window: remove from left, add from right
        for (int i = k - 1; i >= 0; i--) {
            lsum -= nums[i];
            rsum += nums[index];
            index--;

            maxsum = max(maxsum, lsum + rsum);
        }

        return maxsum;
    }
};

int main() {
    int n, k;
    cin >> n;           // size of array
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // array elements
    }

    cin >> k;           // number of cards to pick

    Solution sol;
    cout << sol.maxScore(nums, k) << endl;

    return 0;
}
