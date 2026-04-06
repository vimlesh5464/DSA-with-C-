# 287. Find the Duplicate Number.py - Python skeleton converted from C++

# Original C++ code:
# // Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
# 
# // There is only one repeated number in nums, return this repeated number.
# 
# // You must solve the problem without modifying the array nums and using only constant extra space.
# 
#  
# 
# // Example 1:
# 
# // Input: nums = [1,3,4,2,2]
# // Output: 2
# 
# // Example 2:
# 
# // Input: nums = [3,1,3,4,2]
# // Output: 3
# 
# // Example 3:
# 
# // Input: nums = [3,3,3,3,3]
# // Output: 3
# 
#  
# 
# // Constraints:
# 
# //     1 <= n <= 105
# //     nums.length == n + 1
# //     1 <= nums[i] <= n
# //     All the integers in nums appear only once except for precisely one integer which appears two or more times.
# 
#  
# #include <iostream>
# #include <vector>
# using namespace std;
# 
# class Solution {
# public:
#     int findDuplicate(vector<int>& nums) {
#         int low = 1, high = nums.size() - 1;
#         int duplicate = -1;
# 
#         while (low <= high) {
#             int mid = low + (high - low) / 2;
# 
#             // Count how many numbers are <= mid
#             int count = 0;
#             for (int num : nums) {
#                 if (num <= mid)
#                     count++;
#             }
# 
#             if (count > mid) {
#                 duplicate = mid;
#                 high = mid - 1;  // search left half
#             } else {
#                 low = mid + 1;   // search right half
#             }
#         }
# 
#         return duplicate;
#     }
# };
# 
# // 🔹 Driver code
# int main() {
#     vector<int> nums = {1, 3, 4, 2, 2};
#     Solution sol;
#     cout << sol.findDuplicate(nums) << endl;  // Output: 2
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
