# 239. Sliding Window Maximum.py - Python skeleton converted from C++

# Original C++ code:
# // You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
# 
# // Return the max sliding window.
# 
#  
# 
# // Example 1:
# 
# // Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
# // Output: [3,3,5,5,6,7]
# // Explanation: 
# // Window position                Max
# // ---------------               -----
# // [1  3  -1] -3  5  3  6  7       3
# //  1 [3  -1  -3] 5  3  6  7       3
# //  1  3 [-1  -3  5] 3  6  7       5
# //  1  3  -1 [-3  5  3] 6  7       5
# //  1  3  -1  -3 [5  3  6] 7       6
# //  1  3  -1  -3  5 [3  6  7]      7
# 
# // Example 2:
# 
# // Input: nums = [1], k = 1
# // Output: [1]
# 
#  
# 
# // Constraints:
# 
# //     1 <= nums.length <= 105
# //     -104 <= nums[i] <= 104
# //     1 <= k <= nums.length
# 
#  
# 
# // Approach 1: Brute Force (Easy but Slow)
# 
# // For each window, find the maximum by scanning all k elements.
# 
# // Time Complexity: O(n * k)
# 
# // Space Complexity: O(1)
# 
# #include <iostream>
# #include<vector>
# #include<deque>
# using namespace std;
# 
# class Solution {
# public:
#     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
#         vector<int> result;
#         int n = nums.size();
#         
#         for (int i = 0; i <= n - k; i++) {
#             int windowMax = nums[i];
#             for (int j = i; j < i + k; j++) {
#                 windowMax = max(windowMax, nums[j]);
#             }
#             result.push_back(windowMax);
#         }
#         return result;
#     }
# };
# 
# 
# // 🔹 Approach 2: Optimal using Deque
# 
# // Use deque to keep indices of useful elements.
# 
# // Always keep the deque in decreasing order of values.
# 
# // Front of deque = max in current window.
# 
# // Time Complexity: O(n)
# 
# // Space Complexity: O(k)
# 
# class Solution {
#   public:
#       vector<int> maxSlidingWindow(vector<int>& nums, int k) {
#           deque<int> dq;  // stores indices
#           vector<int> result;
#           
#           for (int i = 0; i < nums.size(); i++) {
#               // Remove indices that are out of the window
#               if (!dq.empty() && dq.front() <= i - k) {
#                   dq.pop_front();
#               }
#               
#               // Remove smaller elements from the back
#               while (!dq.empty() && nums[dq.back()] < nums[i]) {
#                   dq.pop_back();
#               }
#               
#               // Add current index
#               dq.push_back(i);
#               
#               // Start adding results once we have at least k elements
#               if (i >= k - 1) {
#                   result.push_back(nums[dq.front()]);
#               }
#           }
#           return result;
#       }
#   };
#   
# 
# int main() {
#     Solution s;
#     vector<int> nums = {1,3,-1,-3,5,3,6,7};
#     int k = 3;
#     vector<int> ans = s.maxSlidingWindow(nums, k);
#     
#     for (int x : ans) cout << x << " ";
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
