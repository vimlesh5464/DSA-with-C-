# 53. Maximum Subarray.py - Python skeleton converted from C++

# Original C++ code:
# // Given an integer array nums, find the with the largest sum, and return its sum.
# 
#  
# 
# // Example 1:
# 
# // Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
# // Output: 6
# // Explanation: The subarray [4,-1,2,1] has the largest sum 6.
# 
# // Example 2:
# 
# // Input: nums = [1]
# // Output: 1
# // Explanation: The subarray [1] has the largest sum 1.
# 
# // Example 3:
# 
# // Input: nums = [5,4,-1,7,8]
# // Output: 23
# // Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
# 
#  
# 
# // Constraints:
# 
# //     1 <= nums.length <= 105
# //     -104 <= nums[i] <= 104
# 
#  
# 
# // Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
# #include <iostream>
# #include<unordered_map>
# #include<vector>
# using namespace std;
# //🔹 Approaches
# //1. Brute Force (Check All Subarrays)
# // Time Complexity: O(n²) or O(n³)
# // Space Complexity: O(1)
# 
# class Solution {
# public:
#     int maxSubArray(vector<int>& nums) {
#         int n = nums.size();
#         int maxSum = INT_MIN;
#         for(int i = 0; i < n; i++){
#             int sum = 0;
#             for(int j = i; j < n; j++){
#                 sum += nums[j];
#                 maxSum = max(maxSum, sum);
#             }
#         }
#         return maxSum;
#     }
# };
# 
# //2. Kadane’s Algorithm (Optimal) ✅
# // Time Complexity: O(n)
# // Space Complexity: O(1)
# class Solution {
#   public:
#       int maxSubArray(vector<int>& nums) {
#           int maxSum = nums[0];
#           int currentSum = nums[0];
#           for(int i = 1; i < nums.size(); i++){
#               currentSum = max(nums[i], currentSum + nums[i]);
#               maxSum = max(maxSum, currentSum);
#           }
#           return maxSum;
#       }
#   };
# 
#   class Solution {
#     public:
#         int maxSubArray(vector<int>& nums) {
#             int n = nums.size();
#             vector<int> dp(n);
#             dp[0] = nums[0];
#             int maxSum = dp[0];
#     
#             for (int i = 1; i < n; i++) {
#                 dp[i] = max(nums[i], dp[i - 1] + nums[i]);
#                 maxSum = max(maxSum, dp[i]);
#             }
#     
#             return maxSum;
#         }
#     };
#     
# int main() {
#     Solution s;
#     vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
#     cout << "Maximum Subarray Sum: " << s.maxSubArray(nums) << endl;
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
