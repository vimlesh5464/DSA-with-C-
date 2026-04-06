# 189 – Rotate Array.py - Python skeleton converted from C++

# Original C++ code:
# // Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
# 
#  
# 
# // Example 1:
# 
# // Input: nums = [1,2,3,4,5,6,7], k = 3
# // Output: [5,6,7,1,2,3,4]
# // Explanation:
# // rotate 1 steps to the right: [7,1,2,3,4,5,6]
# // rotate 2 steps to the right: [6,7,1,2,3,4,5]
# // rotate 3 steps to the right: [5,6,7,1,2,3,4]
# 
# // Example 2:
# 
# // Input: nums = [-1,-100,3,99], k = 2
# // Output: [3,99,-1,-100]
# // Explanation: 
# // rotate 1 steps to the right: [99,-1,-100,3]
# // rotate 2 steps to the right: [3,99,-1,-100]
# 
#  
# 
# // Constraints:
# 
# //     1 <= nums.length <= 105
# //     -231 <= nums[i] <= 231 - 1
# //     0 <= k <= 105
# 
# 
# //Approach 1: Brute Force (Shift One by One)
# // Time Complexity: O(n*k)
# // Space Complexity: O(1)
# 
# #include <iostream>
# #include<vector>
# using namespace std;
# 
# class Solution {
# public:
#     void leftRotateBruteForce(vector<int>& arr, int k) {
#         int n = arr.size();
#         k = k % n; // handle k > n
# 
#         for (int i = 0; i < k; i++) {
#             int first = arr[0];
#             for (int j = 0; j < n - 1; j++) {
#                 arr[j] = arr[j + 1];
#             }
#             arr[n - 1] = first;
#         }
#     }
# };
# 
# 
# //Approach 2: Using Extra Array
# // Time Complexity: O(n)
# // Space Complexity: O(n)
# 
# class Solution {
#   public:
#       void leftRotateExtraArray(vector<int>& arr, int k) {
#           int n = arr.size();
#           k = k % n;
#   
#           vector<int> temp(n);
#           for (int i = 0; i < n; i++) {
#               temp[i] = arr[(i + k) % n];
#           }
#   
#           arr = temp; // copy back
#       }
#   };
# 
#   //Approach 3: Optimal (Reversal Algorithm)
# //   Time Complexity: O(n)
# // Space Complexity: O(1) ✅
# 
# class Solution {
#   public:
#       void leftRotateReversal(vector<int>& arr, int k) {
#           int n = arr.size();
#           k = k % n;
#   
#           // Step 1: Reverse first k elements
#           reverse(arr.begin(), arr.begin() + k);
#   
#           // Step 2: Reverse remaining n-k elements
#           reverse(arr.begin() + k, arr.end());
#   
#           // Step 3: Reverse whole array
#           reverse(arr.begin(), arr.end());
#       }
#   };
#   
# 
# int main() {
#     Solution s;
#     vector<int> arr = {1, 2, 3, 4, 5};
#     int k = 2;
# 
#     s.leftRotateReversal(arr, k);
# 
#     for (int num : arr) cout << num << " ";
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
