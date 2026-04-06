# Rearrange Array Elements by Sign.py - Python skeleton converted from C++

# Original C++ code:
# // You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
# 
# // You should return the array of nums such that the array follows the given conditions:
# 
# //     Every consecutive pair of integers have opposite signs.
# //     For all integers with the same sign, the order in which they were present in nums is preserved.
# //     The rearranged array begins with a positive integer.
# 
# // Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
# 
#  
# 
# // Example 1:
# 
# // Input: nums = [3,1,-2,-5,2,-4]
# // Output: [3,-2,1,-5,2,-4]
# // Explanation:
# // The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
# // The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
# // Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  
# 
# // Example 2:
# 
# // Input: nums = [-1,1]
# // Output: [1,-1]
# // Explanation:
# // 1 is the only positive integer and -1 the only negative integer in nums.
# // So nums is rearranged to [1,-1].
# 
#  
# 
# // Constraints:
# 
# //     2 <= nums.length <= 2 * 105
# //     nums.length is even
# //     1 <= |nums[i]| <= 105
# //     nums consists of equal number of positive and negative integers.
# 
#  
# // It is not required to do the modifications in-place.
# #include <iostream>
# #include <vector>
# using namespace std;
# 
# //[Naive Approach] Using Rotation in array - O(n^2) Time and O(1) Space
# // Function to right rotate the subarray between out-of-place
# // element and next opposite sign element
# void rightRotate(vector<int>& arr, int start, int end) {
#     int temp = arr[end];
#     for (int i = end; i > start; i--) {
#         arr[i] = arr[i - 1];
#     }
#     arr[start] = temp;
# }
# 
# // Function to rearrange the array
# void rearrange(vector<int>& arr) {
#     int n = arr.size();
# 
#     for (int i = 0; i < n; i++) {
#         
#         // Check if the current positive element is out of place
#         if(arr[i] >= 0 && i % 2 == 1) {
#           
#             // Find the next negative element and rotate the subarray
#             // between these two elements
#         	for(int j = i + 1; j < n; j++) {
#             	if(arr[j] < 0) {
#                 	rightRotate(arr, i, j);
#               		break;
#                 }
#             }
#         }
#       	
#       	// Check if the current negative element is out of place
#       	else if(arr[i] < 0 && i % 2 == 0){
#         	
#             // Find the next positive element and rotate the subarray
#             // between these two elements
#             for(int j = i + 1; j < n; j++) {
#             	if(arr[j] >= 0) {
#                 	rightRotate(arr, i, j);
#               		break;
#                 }
#             }
#         }
#     }
# }
# 
# //[Expected Approach] Using Two Pointers - O(n) Time and O(n) Space
# void rearrange(vector<int>& arr) {
#   vector<int> pos, neg;
# 
#   // Separate positive and negative numbers
#   for (int i = 0; i < arr.size(); i++) {
#       if (arr[i] >= 0)
#           pos.push_back(arr[i]);
#       else
#           neg.push_back(arr[i]);
#   }
# 
#   int posIdx = 0, negIdx = 0;
#   int i = 0;
# 
#   // Place positive and negative numbers alternately
#   // in the original array
#   while (posIdx < pos.size() && negIdx < neg.size()) {
#       if (i % 2 == 0)
#           arr[i++] = pos[posIdx++];
#       else 
#           arr[i++] = neg[negIdx++];
#   }
# 
#   // Append remaining positive numbers (if any)
#   while (posIdx < pos.size())
#       arr[i++] = pos[posIdx++];
# 
#   // Append remaining negative numbers (if any)
#   while (negIdx < neg.size())
#       arr[i++] = neg[negIdx++];
# }
# 
# int main() {
#     vector<int> arr = {1, 2, 3, -4, -1, 4};
# 
#     rearrange(arr);
# 	for (int i = 0; i < arr.size(); i++)
#         cout << arr[i] << " ";
#   
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
