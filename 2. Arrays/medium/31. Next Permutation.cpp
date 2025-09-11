#include <iostream>
#include<vector>
#include<set>
using namespace std;
// 🔹 Approaches
// 1. Brute Force
// Generate all permutations, sort them, and find the next permutation after the current one.
// Time Complexity: O(n! * n) → very slow.
// Space Complexity: O(n!)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> perms;
        sort(nums.begin(), nums.end());
        do {
            perms.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));

        for(int i = 0; i < perms.size(); i++){
            if(perms[i] == nums){
                if(i+1 < perms.size()){
                    nums = perms[i+1];
                } else {
                    nums = perms[0];
                }
                break;
            }
        }
    }
};

// 🔹 Approach (Optimal In-Place)
// Steps Recap:
// Traverse from right to left to find the first decreasing element (ind).
// If no such element exists → array is in descending order → reverse the whole array.
// Otherwise, find the smallest number greater than nums[ind] on the right and swap.
// Reverse the subarray after ind to get the next lexicographical permutation.
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        // Step 1: Find first decreasing element from the right
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        // Step 2: If no decreasing element, reverse entire array
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find element just larger than nums[ind] and swap
        for(int i = n-1; i > ind; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 4: Reverse subarray after index ind
        reverse(nums.begin() + ind + 1, nums.end());
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 5, 4, 2};

    cout << "Original Array: ";
    for(int num : nums) cout << num << " ";
    cout << endl;

    s.nextPermutation(nums);

    cout << "Next Permutation: ";
    for(int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}

