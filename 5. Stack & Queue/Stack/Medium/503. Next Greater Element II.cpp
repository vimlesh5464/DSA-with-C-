#include<iostream>
#include<vector>
#include<stack>
using namespace std;


// ✅ Time Complexity: O(n) (each element pushed/popped at most once).
// ✅ Space Complexity: O(n) (for stack).
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;

        // Traverse twice to simulate circular array
        for (int i = 2 * n - 1; i >= 0; i--) {
            int num = nums[i % n]; // wrap index

            // Pop smaller or equal elements
            while (!stk.empty() && stk.top() <= num) {
                stk.pop();
            }

            // Only fill answers in first pass
            if (i < n && !stk.empty()) {
                res[i] = stk.top();
            }

            // Push current element
            stk.push(num);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
