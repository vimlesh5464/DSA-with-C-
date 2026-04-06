# 560. Subarray Sum Equals K.py - Python skeleton converted from C++

# Original C++ code:
# // Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
# 
# // A subarray is a contiguous non-empty sequence of elements within an array.
# 
#  
# 
# // Example 1:
# 
# // Input: nums = [1,1,1], k = 2
# // Output: 2
# 
# // Example 2:
# 
# // Input: nums = [1,2,3], k = 3
# // Output: 2
# 
#  
# 
# // Constraints:
# 
# //     1 <= nums.length <= 2 * 104
# //     -1000 <= nums[i] <= 1000
# //     -107 <= k <= 107
# 
#  
# 
# #include <iostream>
# #include<vector>
# #include<unordered_map>
# using namespace std;
# // Brute Force ApproachIdea:
# // Check all possible subarrays and calculate their sum.
# // If sum equals k, increment the count.
# // Simple, but O(n²) time, inefficient for large arrays.
# // Time	O(n²) → nested loops to check all subarrays
# // Space	O(1) → only variables for sum and count
# class Solution {
#   public:
#       int subarraySum(vector<int>& nums, int k) {
#           int n = nums.size();
#           int count = 0;
#   
#           // Iterate over all subarrays
#           for(int i = 0; i < n; i++) {
#               int sum = 0;
#               for(int j = i; j < n; j++) {
#                   sum += nums[j]; // sum of subarray nums[i..j]
#                   if(sum == k) count++; // check if sum equals k
#               }
#           }
#   
#           return count;
#       }
#   };
# 
# 
# // Approach (Prefix Sum + HashMap, Optimal)
# // Maintain a prefix sum array: prefixsum[i] = sum of elements from 0 to i.
# // Use a hashmap to store frequency of prefix sums seen so far.
# // For each prefix sum prefixsum[j], check if (prefixsum[j] - k) exists in the map:
# // If yes, it means there is a subarray ending at j whose sum = k.
# // Increment the count by the frequency of (prefixsum[j] - k).
# // Update the hashmap with prefixsum[j].
# // This allows us to find all subarrays with sum k in O(n) time.
# // Complexity Analysis
# // Aspect	Complexity
# // Time	O(n) → one pass for prefix sum + one pass to count subarrays
# // Space	O(n) → hashmap for prefix sums
# 
# class Solution {
# public:
#     int subarraySum(vector<int>& nums, int k) {
#         int n = nums.size();
#         int count = 0;
#         vector<int> prefixsum(n, 0);
#         prefixsum[0] = nums[0];
# 
#         // Step 1: Compute prefix sum array
#         for (int i = 1; i < n; i++) {
#             prefixsum[i] = prefixsum[i - 1] + nums[i];
#         }
# 
#         unordered_map<int, int> m; // prefix sum frequency map
# 
#         // Step 2: Count subarrays
#         for (int j = 0; j < n; j++) {
#             if (prefixsum[j] == k) count++; // subarray from start
# 
#             int val = prefixsum[j] - k;
#             if (m.find(val) != m.end()) count += m[val]; // subarray found
# 
#             m[prefixsum[j]]++; // update map
#         }
# 
#         return count;
#     }
# };
# 
# int main() {
#     Solution s;
#     vector<int> nums = {1, 1, 1};
#     int k = 2;
# 
#     int result = s.subarraySum(nums, k);
#     cout << "Number of subarrays with sum " << k << " is: " << result << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
