#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& result) {
        // Include the current subset in the result
        result.push_back(subset);

        // Explore further subsets
        for (int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);              // choose
            backtrack(nums, i + 1, subset, result); // explore
            subset.pop_back();                      // un-choose (backtrack)
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(nums, 0, subset, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = sol.subsets(nums);

    cout << "All subsets of [1,2,3]:\n";
    for (auto& subset : ans) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
