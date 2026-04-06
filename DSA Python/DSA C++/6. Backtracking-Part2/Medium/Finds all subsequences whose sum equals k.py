# Finds all subsequences whose sum equals k.py - Python skeleton converted from C++

# Original C++ code:
# // Given an array arr and target sum k, check whether there exists a subsequence 
# //such that the sum of all elements in the subsequence equals the given target sum(k).
# 
# 
# // Example:
# 
# // Input:  arr = [10,1,2,7,6,1,5], k = 8.
# // Output:  Yes
# // Explanation:  Subsequences like [2, 6], [1, 7] sum upto 8
# 
# // Input:  arr = [2,3,5,7,9], k = 100. 
# // Output:  No
# // Explanation:  No subsequence can sum upto 100
# 
# // Your Task:
# // You don't need to read or print anything. Your task is to complete the boolean function checkSubsequenceSum() which takes N, arr and K as input parameter and returns true/false based on the whether any subsequence with sum K could be found.
# 
# 
# // Expected Time Complexity: O(N * K).
# // Expected Auxiliary Space: O(N * K).
# 
# 
# // Constraints:
# // 1 <= arr.length <= 2000
# // 1 <= arr[i] <= 1000
# // 1 <= target <= 2000
# // #include <iostream>
# // #include <vector>
# // using namespace std;
# 
# // void subseq(vector<int> &arr, int i, vector<int> &subset, vector<vector<int>> &ans, int currentSum, int target) {
# //     // Base case
# //     if (i == arr.size()) {
# //         if (currentSum == target && !subset.empty()) {
# //             ans.push_back(subset);
# //         }
# //         return;
# //     }
# 
# //     // Include current element
# //     subset.push_back(arr[i]);
# //     subseq(arr, i + 1, subset, ans, currentSum + arr[i], target);
# //     subset.pop_back();
# 
# //     // Exclude current element
# //     subseq(arr, i + 1, subset, ans, currentSum, target);
# // }
# 
# // int main() {
# //     vector<vector<int>> ans;
# //     vector<int> subset;
# //     vector<int> arr = {3, 1, 2};
# //     int target = 2;
# 
# //     subseq(arr, 0, subset, ans, 0, target);
# 
# //     cout << "Subsequences with sum = " << target << ":\n";
# //     for (int i = 0; i < ans.size(); i++) {
# //         for (int j = 0; j < ans[i].size(); j++) {
# //             cout << ans[i][j] << " ";
# //         }
# //         cout << endl;
# //     }
# //     return 0;
# // }
# 
# #include <iostream>
# #include <vector>
# using namespace std;
# 
# class Solution {
# public:
#     // Recursive helper function
#     bool helper(vector<int>& arr, int i, vector<int>& subset, vector<vector<int>>& ans, int k, int currsum) {
#         // base condition
#         if (i == arr.size()) {
#             if (currsum == k && !subset.empty()) {
#                 ans.push_back(subset);
#                 return true;
#             }
#             return false;
#         }
# 
#         // include current element
#         subset.push_back(arr[i]);
#         bool include = helper(arr, i + 1, subset, ans, k, currsum + arr[i]);
#         subset.pop_back();
# 
#         // exclude current element
#         bool exclude = helper(arr, i + 1, subset, ans, k, currsum);
# 
#         // return true if any subsequence sum == k
#         return include || exclude;
#     }
# 
#     bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
#         vector<vector<int>> ans;
#         vector<int> subset;
#         bool found = helper(arr, 0, subset, ans, k, 0);
# 
#         // print all valid subsequences
#         if (found) {
#             cout << "Subsequences with sum " << k << " are:\n";
#             for (auto& vec : ans) {
#                 cout << "[ ";
#                 for (int val : vec) cout << val << " ";
#                 cout << "]\n";
#             }
#         } else {
#             cout << "No subsequence with sum " << k << " found.\n";
#         }
# 
#         return found;
#     }
# };
# 
# int main() {
#     vector<int> arr = {3, 1, 2};
#     int k = 3;
#     int n = arr.size();
# 
#     Solution sol;
#     bool result = sol.checkSubsequenceSum(n, arr, k);
# 
#     cout << "\nResult: " << (result ? "True" : "False") << endl;
#     return 0;
# }
# 
# // #include <iostream>
# // #include <vector>
# // using namespace std;
# 
# // class Solution {
# // public:
# //     bool helper(vector<int>& arr, int i, int k, int currsum) {
# //         // base case
# //         if (i == arr.size()) {
# //             return currsum == k;
# //         }
# 
# //         // include current element
# //         if (helper(arr, i + 1, k, currsum + arr[i])) return true;
# 
# //         // exclude current element
# //         if (helper(arr, i + 1, k, currsum)) return true;
# 
# //         // no valid subsequence found
# //         return false;
# //     }
# 
# //     bool checkSubsequenceSum(vector<int>& arr, int k) {
# //         return helper(arr, 0, k, 0);
# //     }
# // };
# 
# // int main() {
# //     vector<int> arr = {3, 1, 2};
# //     int k = 3;
# 
# //     Solution sol;
# //     bool result = sol.checkSubsequenceSum(arr, k);
# 
# //     cout << (result ? "True" : "False") << endl;
# //     return 0;
# // }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
