# 31. Next Permutation.py - Python skeleton converted from C++

# Original C++ code:
# // A permutation of an array of integers is an arrangement of its members 
# //into a sequence or linear order.
# 
# //     For example, for arr = [1,2,3], the following are all the permutations of arr:
# // [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
# 
# // The next permutation of an array of integers is the next lexicographically greater
# // permutation of its integer. More formally, if all the permutations of the array 
# //are sorted in one container according to their lexicographical order, then the 
# //next permutation of that array is the permutation that follows it in the sorted 
# //container. If such arrangement is not possible, the array must be rearranged as 
# //the lowest possible order (i.e., sorted in ascending order).
# 
# //     For example, the next permutation of arr = [1,2,3] is [1,3,2].
# //     Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
# //     While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
# 
# // Given an array of integers nums, find the next permutation of nums.
# 
# // The replacement must be in place and use only constant extra memory.
# 
#  
# 
# // Example 1:
# 
# // Input: nums = [1,2,3]
# // Output: [1,3,2]
# 
# // Example 2:
# 
# // Input: nums = [3,2,1]
# // Output: [1,2,3]
# 
# // Example 3:
# 
# // Input: nums = [1,1,5]
# // Output: [1,5,1]
# 
#  
# 
# // Constraints:
# 
# //     1 <= nums.length <= 100
# //     0 <= nums[i] <= 100
# 
#  
# #include <iostream>
# #include<vector>
# #include<set>
# using namespace std;
# // 🔹 Approaches
# // 1. Brute Force
# // Generate all permutations, sort them, and find the next permutation after the current one.
# // Time Complexity: O(n! * n) → very slow.
# // Space Complexity: O(n!)
# class Solution {
#   public:
#       void nextPermutation(vector<int>& nums) {
#           vector<vector<int>> perms;
#           vector<int> original = nums;  // store original input
#   
#           sort(nums.begin(), nums.end()); // start generating permutations
#           do {
#               perms.push_back(nums);
#           } while(next_permutation(nums.begin(), nums.end()));
#   
#           for(int i = 0; i < perms.size(); i++){
#               if(perms[i] == original){  // compare with original
#                   if(i+1 < perms.size()){
#                       nums = perms[i+1];
#                   } else {
#                       nums = perms[0]; // wrap to smallest
#                   }
#                   break;
#               }
#           }
#       }
#   };
# 
# // 🔹 Approach (Optimal In-Place)
# // Steps Recap:
# // Traverse from right to left to find the first decreasing element (ind).
# // If no such element exists → array is in descending order → reverse the whole array.
# // Otherwise, find the smallest number greater than nums[ind] on the right and swap.
# // Reverse the subarray after ind to get the next lexicographical permutation.
# //Time Complexity: O(n)
# //Space Complexity: O(1)
# class Solution {
# public:
#     void nextPermutation(vector<int>& nums) {
#         int n = nums.size();
#         int ind = -1;
# 
#         // Step 1: Find first decreasing element from the right
#         for(int i = n-2; i >= 0; i--){
#             if(nums[i] < nums[i+1]){
#                 ind = i;
#                 break;
#             }
#         }
# 
#         // Step 2: If no decreasing element, reverse entire array
#         if(ind == -1){
#             reverse(nums.begin(), nums.end());
#             return;
#         }
# 
#         // Step 3: Find element just larger than nums[ind] and swap
#         for(int i = n-1; i > ind; i--){
#             if(nums[i] > nums[ind]){
#                 swap(nums[i], nums[ind]);
#                 break;
#             }
#         }
# 
#         // Step 4: Reverse subarray after index ind
#         reverse(nums.begin() + ind + 1, nums.end());
#     }
# };
# 
# int main() {
#     Solution s;
#     vector<int> nums = {1, 3, 5, 4, 2};
# 
#     cout << "Original Array: ";
#     for(int num : nums) cout << num << " ";
#     cout << endl;
# 
#     s.nextPermutation(nums);
# 
#     cout << "Next Permutation: ";
#     for(int num : nums) cout << num << " ";
#     cout << endl;
# 
#     return 0;
# }
# 

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
