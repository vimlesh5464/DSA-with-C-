# 60. Permutation Sequence.py - Python skeleton converted from C++

# Original C++ code:
# // The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
# 
# // By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
# 
# //     "123"
# //     "132"
# //     "213"
# //     "231"
# //     "312"
# //     "321"
# 
# // Given n and k, return the kth permutation sequence.
# 
#  
# 
# // Example 1:
# 
# // Input: n = 3, k = 3
# // Output: "213"
# 
# // Example 2:
# 
# // Input: n = 4, k = 9
# // Output: "2314"
# 
# // Example 3:
# 
# // Input: n = 3, k = 1
# // Output: "123"
# 
#  
# 
# // Constraints:
# 
# //     1 <= n <= 9
# //     1 <= k <= n!
# 
# #include<iostream>
# #include<vector>
# #include<string>
# using namespace std;
# class Solution {
#   public:
#       void solve(int idx, vector<int> &nums, vector<string> &res) {
#           if (idx == nums.size()) {
#               string s = "";
#               for (int x : nums) s += to_string(x);
#               res.push_back(s);
#               return;
#           }
#           for (int i = idx; i < nums.size(); i++) {
#               swap(nums[i], nums[idx]);
#               solve(idx + 1, nums, res);
#               swap(nums[i], nums[idx]);   // backtrack
#           }
#       }
#   
#       string getPermutation(int n, int k) {
#           vector<int> nums;
#           for (int i = 1; i <= n; i++) nums.push_back(i);
#   
#           vector<string> all;  // saare permutations
#           solve(0, nums, all);
#   
#           sort(all.begin(), all.end()); // lexicographical order
#   
#           return all[k - 1];  // k-th permutation
#       }
#   };
# 
#   class Solution {
#     public:
#         string getPermutation(int n, int k) {
#             vector<int> nums;
#             for(int i=1; i<=n; i++) nums.push_back(i);
#     
#             vector<int> fact(n);
#             fact[0] = 1;
#             for(int i=1; i<n; i++)
#                 fact[i] = fact[i-1] * i;
#     
#             k--;  // 0-based
#             string ans = "";
#     
#             for(int i=n-1; i>=0; i--) {
#                 int idx = k / fact[i];
#                 ans += to_string(nums[idx]);
#                 nums.erase(nums.begin() + idx);
#                 k %= fact[i];
#             }
#     
#             return ans;
#         }
#     };
#     

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
