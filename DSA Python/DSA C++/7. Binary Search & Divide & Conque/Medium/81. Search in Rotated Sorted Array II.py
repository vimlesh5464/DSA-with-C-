# 81. Search in Rotated Sorted Array II.py - Python skeleton converted from C++

# Original C++ code:
# // There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
# 
# // Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
# 
# // Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
# 
# // You must decrease the overall operation steps as much as possible.
# 
#  
# 
# // Example 1:
# 
# // Input: nums = [2,5,6,0,0,1,2], target = 0
# // Output: true
# 
# // Example 2:
# 
# // Input: nums = [2,5,6,0,0,1,2], target = 3
# // Output: false
# 
#  
# 
# // Constraints:
# 
# //     1 <= nums.length <= 5000
# //     -104 <= nums[i] <= 104
# //     nums is guaranteed to be rotated at some pivot.
# //     -104 <= target <= 104
# 
# 
# #include <vector>
# #include <iostream>
# using namespace std;
# 
# class Solution {
# public:
#     bool search(std::vector<int>& nums, int target) {
#         int low = 0;
#         int high = nums.size() - 1;
# 
#         while (low <= high) {
#             int mid = low + (high - low) / 2;
# 
#             if (nums[mid] == target) {
#                 return true;
#             }
# 
#             // Handle duplicates (worst-case O(n))
#             if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
#                 low++;
#                 high--;
#                 continue;
#             }
# 
#             // Left half is sorted
#             if (nums[low] <= nums[mid]) {
#                 if (nums[low] <= target && target < nums[mid]) {
#                     high = mid - 1;
#                 } else {
#                     low = mid + 1;
#                 }
#             }
#             // Right half is sorted
#             else {
#                 if (nums[mid] < target && target <= nums[high]) {
#                     low = mid + 1;
#                 } else {
#                     high = mid - 1;
#                 }
#             }
#         }
# 
#         return false;
#     }
# };
# 
# int main() {
#     Solution s;
#     int n, target;
# 
#     // Input size of array
#     cout << "Enter the size of the array: ";
#     cin >> n;
# 
#     vector<int> nums(n);
# 
#     // Input array elements
#     cout << "Enter " << n << " elements of the rotated sorted array: ";
#     for (int i = 0; i < n; i++) {
#         cin >> nums[i];
#     }
# 
#     // Input target
#     cout << "Enter the target to search: ";
#     cin >> target;
# 
#     // Search and output
#     if (s.search(nums, target)) {
#         cout << "Target " << target << " is present in the array." << std::endl;
#     } else {
#         cout << "Target " << target << " is NOT present in the array." << std::endl;
#     }
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
