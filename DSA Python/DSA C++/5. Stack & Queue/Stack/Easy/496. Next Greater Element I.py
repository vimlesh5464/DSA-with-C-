# 496. Next Greater Element I.py - Python skeleton converted from C++

# Original C++ code:
# // 496. Next Greater Element I
# // Solved
# // Easy
# // Topics
# // premium lock iconCompanies
# 
# // The next greater element of some element x in an array is the first greater 
# //element that is to the right of x in the same array.
# 
# // You are given two distinct 0-indexed integer arrays nums1 and nums2, 
# //where nums1 is a subset of nums2.
# 
# // For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] 
# //and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
# 
# // Return an array ans of length nums1.length such that ans[i] is the next greater 
# //element as described above.
# 
#  
# 
# // Example 1:
# 
# // Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
# // Output: [-1,3,-1]
# // Explanation: The next greater element for each value of nums1 is as follows:
# // - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
# // - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
# // - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
# 
# // Example 2:
# 
# // Input: nums1 = [2,4], nums2 = [1,2,3,4]
# // Output: [3,-1]
# // Explanation: The next greater element for each value of nums1 is as follows:
# // - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
# // - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
# 
#  
# 
# // Constraints:
# 
# //     1 <= nums1.length <= nums2.length <= 1000
# //     0 <= nums1[i], nums2[i] <= 104
# //     All integers in nums1 and nums2 are unique.
# //     All the integers of nums1 also appear in nums2.
# 
#  
# 
# #include<iostream>
# #include<vector>
# #include<stack>
# #include<unordered_map>
# using namespace std;
# 
# class Solution {
#   public:
#       vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
#           vector<int> res(nums1.size(), -1);
#   
#           for (int i = 0; i < nums1.size(); i++) {
#               for (int j = 0; j < nums2.size(); j++) {
#   
#                   // find nums1[i] in nums2
#                   if (nums2[j] == nums1[i]) {
#   
#                       // search on the right side
#                       for (int k = j + 1; k < nums2.size(); k++) {
#                           if (nums2[k] > nums1[i]) {
#                               res[i] = nums2[k];
#                               break;
#                           }
#                       }
#                       break; // nums1[i] found, no need to continue j
#                   }
#               }
#           }
#           return res;
#       }
#   };
# 
# class Solution {
# public:
#     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
#         unordered_map<int, int> mp; // store next greater for nums2 elements
#         stack<int> st;
# 
#         // Traverse nums2 from right to left
#         for (int i = nums2.size() - 1; i >= 0; i--) {
#             int num = nums2[i];
#             while (!st.empty() && st.top() <= num) {
#                 st.pop();
#             }
#             if (!st.empty()) {
#                 mp[num] = st.top();
#             } else {
#                 mp[num] = -1;
#             }
#             st.push(num);
#         }
# 
#         // Build answer for nums1
#         vector<int> ans;
#         for (int num : nums1) {
#             ans.push_back(mp[num]);
#         }
# 
#         return ans; 
#     }
# };
# 
# int main() {
#     Solution sol;
#     vector<int> nums1 = {4, 1, 2};
#     vector<int> nums2 = {1, 3, 4, 2};
# 
#     vector<int> ans = sol.nextGreaterElement(nums1, nums2);
# 
#     cout << "Next Greater Elements: ";
#     for (int x : ans) cout << x << " ";
#     cout << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
