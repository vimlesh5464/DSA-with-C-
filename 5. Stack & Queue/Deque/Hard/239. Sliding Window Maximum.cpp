#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices that are out of the current window
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // Remove smaller elements (not useful anymore)
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // Add current index
            dq.push_back(i);

            // Store max (when the first window is complete)
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximum: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
