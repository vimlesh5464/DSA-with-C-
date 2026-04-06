# Remove duplicates from Sorted Array.py - Python skeleton converted from C++

# Original C++ code:
# // Given a sorted array arr[] of size n, the goal is to rearrange the array so that all distinct elements appear at the beginning in sorted order. Additionally, return the length of this distinct sorted subarray.
# 
# // Note: The elements after the distinct ones can be in any order and hold any value, as they don't affect the result.
# 
# // Examples: 
# 
# //     Input: arr[] = [2, 2, 2, 2, 2]
# //     Output: [2]
# //     Explanation: All the elements are 2, So only keep one instance of 2.
# 
# //     Input: arr[] = [1, 2, 2, 3, 4, 4, 4, 5, 5]
# //     Output: [1, 2, 3, 4, 5]
# 
# //     Input: arr[] = [1, 2, 3]
# //     Output: [1, 2, 3]
# //     Explanation : No change as all elements are distinct.
# #include <iostream>
# #include <vector>
# #include <unordered_set>
# using namespace std;
# 
# //Using Hash Set - Works for Unsorted Also - O(n) Time and O(n) Space
# int removeDuplicates(vector<int>& arr) {
#   
#     // To track seen elements
#     unordered_set<int> s; 
#   
#     // To maintain the new size of the array
#     int idx = 0;  
# 
#     for (int i = 0; i < arr.size(); i++) {
#         if (s.find(arr[i]) == s.end()) { 
#             s.insert(arr[i]);  
#             arr[idx++] = arr[i];  
#         }
#     }
#  
#     // Return the size of the array 
#     // with unique elements
#     return s.size(); 
# }
# 
# //Expected Approach - O(n) Time and O(1) Space
# 
# int removeDuplicates(vector<int>& arr) {
#   int n = arr.size();
#   if (n <= 1)
#       return n;
# 
#   // Start from the second element
#   int idx = 1; 
# 
#   for (int i = 1; i < n; i++) {
#       if (arr[i] != arr[i - 1]) {
#           arr[idx++] = arr[i];
#       }
#   }
#   return idx;
# }
# 
# int main() {
#     vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};
#     int newSize = removeDuplicates(arr);
#     for (int i = 0; i < newSize; i++) 
#         cout << arr[i] << " ";
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
