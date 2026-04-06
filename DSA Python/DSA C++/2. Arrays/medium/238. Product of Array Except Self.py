# 238. Product of Array Except Self.py - Python skeleton converted from C++

# Original C++ code:
# // Given an integer array nums, return an array answer such that answer[i] is equal 
# //to the product of all the elements of nums except nums[i].
# 
# // The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
# 
# // You must write an algorithm that runs in O(n) time and without using the division 
# //operation.
# 
#  
# 
# // Example 1:
# 
# // Input: nums = [1,2,3,4]
# // Output: [24,12,8,6]
# 
# // Example 2:
# 
# // Input: nums = [-1,1,0,-3,3]
# // Output: [0,0,9,0,0]
# 
#  
# 
# // Constraints:
# 
# //     2 <= nums.length <= 105
# //     -30 <= nums[i] <= 30
# //     The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
# 
#  
# #include <iostream>
# #include<vector>
# using namespace std;
# // Brute Force ApproachIdea:
# // For each element nums[i], calculate the product of all elements except itself by iterating over the entire array.
# // Simple but O(n²) time, which is inefficient for large arrays.
# //Space O(n) → output array
# class Solution {
#   public:
#       vector<int> productExceptSelf(vector<int>& nums) {
#           int n = nums.size();
#           vector<int> ans(n, 1);
#   
#           for(int i = 0; i < n; i++){
#               int prod = 1;
#               for(int j = 0; j < n; j++){
#                   if(i != j) prod *= nums[j]; // multiply all except nums[i]
#               }
#               ans[i] = prod;
#           }
#   
#           return ans;
#       }
#   };
#   
# // Approach (Optimal, O(n) time, O(1) extra space)
# // Create prefix products:
# // ans1[i] stores the product of all elements before index i.
# // Iterate backward to include suffix products:
# // Use a variable suffix to store the product of elements after index i.
# // Multiply ans1[i] by suffix for the final result.
# class Solution {
# public:
#     vector<int> productExceptSelf(vector<int>& nums) {
#         int n = nums.size();
#         vector<int> ans1(n, 1); // prefix product array
# 
#         // Step 1: compute prefix products
#         for(int i = 1; i < n; i++){
#             ans1[i] = ans1[i-1] * nums[i-1];
#         }
# 
#         // Step 2: include suffix products
#         int suffix = 1;
#         for(int i = n-1; i >= 0; i--){
#             ans1[i] *= suffix;
#             suffix *= nums[i];
#         }
# 
#         return ans1;
#     }
# };
# 
# int main() {
#     Solution s;
#     vector<int> nums = {1, 2, 3, 4};
#     vector<int> res = s.productExceptSelf(nums);
# 
#     cout << "Product of Array Except Self: ";
#     for(int val : res) cout << val << " ";
#     cout << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
