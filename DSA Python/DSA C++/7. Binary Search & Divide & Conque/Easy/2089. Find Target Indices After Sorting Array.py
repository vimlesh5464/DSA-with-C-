# 2089. Find Target Indices After Sorting Array.py - Python skeleton converted from C++

# Original C++ code:
# #include <iostream>
# #include <vector>
# #include <algorithm>
# using namespace std;
# 
# class Solution {
#   public:
#       vector<int> targetIndices(vector<int>& nums, int target) {
#           int countLess = 0;   // Count of elements < target
#           int countEqual = 0;  // Count of elements == target
#   
#           for(int num : nums) {
#               if(num < target) countLess++;
#               else if(num == target) countEqual++;
#           }
#   
#           vector<int> ans;
#           for(int i = 0; i < countEqual; i++) {
#               ans.push_back(countLess + i);
#           }
#   
#           return ans;
#       }
#   };
# 
# // Function to return indices of target value k in sorted array
# vector<int> count_el(vector<int> nums, int k) {
#     vector<int> ans;
# 
#     // Step 1: Sort the array
#     sort(nums.begin(), nums.end());
# 
#     // Step 2: Collect indices where value == k
#     for(int i = 0; i < nums.size(); i++) {
#         if(nums[i] == k) {
#             ans.push_back(i);  // store index in sorted array
#         }
#     }
# 
#     // Step 3: Return indices vector
#     return ans;
# }
# 
# int main() {
#     int n;
#     cin >> n;                 // Input size
#     vector<int> nums(n);
# 
#     // Input array elements
#     for(int i = 0; i < n; i++) {
#         cin >> nums[i];
#     }  
# 
#     int k;
#     cin >> k;                 // Input target value
# 
#     // Call function
#     vector<int> indices = count_el(nums, k);
# 
#     // Print count
#     cout << indices.size() << endl;
# 
#     // Print indices
#     for(int idx : indices) {
#         cout << idx << " ";
#     }
#     cout << endl;
# 
#     return 0;
# }
# 

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
