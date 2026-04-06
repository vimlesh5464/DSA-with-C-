# Reverse an Array in groups of given size.py - Python skeleton converted from C++

# Original C++ code:
# // Given an array arr[] and an integer k, find the array after reversing every subarray of consecutive k elements in place. If the last subarray has fewer than k elements, reverse it as it is. Modify the array in place, do not return anything.
# 
# // Examples: 
# 
# //     Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8], k = 3
# //     Output: [3, 2, 1, 6, 5, 4, 8, 7]
# //     Explanation: Elements is reversed: [1, 2, 3] → [3, 2, 1], [4, 5, 6] → [6, 5, 4], and the last group [7, 8](size < 3) is reversed as [8, 7]. 
# 
# //     Input: arr[] = [1, 2, 3, 4, 5], k = 3
# //     Output: [3, 2, 1, 5, 4]
# //     Explanation: First group consists of elements 1, 2, 3. Second group consists of 4, 5.
# 
# //     Input: arr[] = [5, 6, 8, 9], k = 5
# //     Output: [9, 8, 6, 5]
# //     Explanation: Since k is greater than array size, the entire array is reversed.
# #include <iostream>
# #include <vector>
# using namespace std;
# 
# void reverseInGroups(vector<int>& arr, int k){
#     
#     // Get the size of the array
#     int n = arr.size();  
# 
#     for (int i = 0; i < n; i += k) {
#         int left = i;
# 
#         // to handle case when k is not multiple of n
#         int right = min(i + k - 1, n - 1);
# 
#         // reverse the sub-array [left, right]
#         while (left < right)  {
#             swap(arr[left++], arr[right--]);
#         }
#     }
# }
# 
# int main() {
#   
#     vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8}; 
#     int k = 3; 
#     reverseInGroups(arr, k); 
# 
#     for (int num : arr)
#         cout << num << " ";
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
