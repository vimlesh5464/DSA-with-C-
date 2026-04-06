# 136. Single Number.py - Python skeleton converted from C++

# Original C++ code:
# // Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
# 
# // You must implement a solution with a linear runtime complexity and use only constant extra space.
# 
#  
# 
# // Example 1:
# 
# // Input: nums = [2,2,1]
# 
# // Output: 1
# 
# // Example 2:
# 
# // Input: nums = [4,1,2,1,2]
# 
# // Output: 4
# 
# // Example 3:
# 
# // Input: nums = [1]
# 
# // Output: 1
# 
#  
# 
# // Constraints:
# 
# //     1 <= nums.length <= 3 * 104
# //     -3 * 104 <= nums[i] <= 3 * 104
# //     Each element in the array appears twice except for one element which appears only once.
# 
# // Approaches
# // 1. Using Hash Map (Count Frequency)
# // Time Complexity: O(n)
# // Space Complexity: O(n)
# 
# #include <iostream>
# #include<unordered_map>
# #include<vector>
# using namespace std;
# 
# class Solution {
# public:
#     int singleNumber(vector<int>& nums) {
#         unordered_map<int,int> freq;
#         for(int num : nums)
#             freq[num]++;
#             for (pair<const int, int> &p : freq) {
#               if (p.second == 1)
#                   return p.first;
#           }    
#         // for(auto &p : freq)
#         //     if(p.second == 1) return p.first;
#         return -1;
#         
#     }
# };
# 
# //2. Using XOR (Optimal) ✅
# // Time Complexity: O(n)
# // Space Complexity: O(1)
# class Solution {
#   public:
#       int singleNumber(vector<int>& nums) {
#           int result = 0;
#           for(int num : nums)
#               result ^= num; // XOR all elements
#           return result;
#       }
#   };
#   
# 
# int main() {
#     Solution s;
#     vector<int> nums = {4,1,2,1,2};
#     cout << "Single Number: " << s.singleNumber(nums) << endl;
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
