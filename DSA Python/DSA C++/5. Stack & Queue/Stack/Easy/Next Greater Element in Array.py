# Next Greater Element in Array.py - Python skeleton converted from C++

# Original C++ code:
# // You are given an array arr[] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
# // If there does not exist next greater of current element, then next greater element for current element is -1.
# 
# // Examples
# 
# // Input: arr[] = [1, 3, 2, 4]
# // Output: [3, 4, 4, -1]
# // Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.
# 
# // Input: arr[] = [6, 8, 0, 1, 3]
# // Output: [8, -1, 1, 3, -1]
# // Explanation: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1, for 1 it is 3 and then for 3 there is no larger element on right and hence -1.
# 
# // Input: arr[] = [1, 2, 3, 5]
# // Output: [2, 3, 5, -1]
# // Explanation: For a sorted array, the next element is next greater element also except for the last element.
# 
# // Input: arr[] = [5, 4, 3, 1]
# // Output: [-1, -1, -1, -1]
# // Explanation: There is no next greater element for any of the elements in the array, so all are -1.
# 
# // Constraints:
# // 1 ≤ arr.size() ≤ 106
# // 0 ≤ arr[i] ≤ 109
# #include <iostream>
# #include <vector>
# #include <stack>
# using namespace std;
# 
# vector<int> nextLargerElement(vector<int> &arr) {
#     int n = arr.size();
#     vector<int> res(n, -1);
# 
#     // iterate through each element in the array
#     for (int i = 0; i < n; i++) {
# 
#         // check for the next greater element
#         // in the rest of the array
#         for (int j = i + 1; j < n; j++) {
#             if (arr[j] > arr[i]) {
#                 res[i] = arr[j];
#                 break;
#             }
#         }
#     }
# 
#     return res;
# }
# 
# vector<int> nextLargerElement(vector<int> &arr) {
#   int n = arr.size();
#   vector<int> res(n, -1);
#   stack<int> stk;
# 
#   for (int i = n - 1; i >= 0; i--) {
# 
#       // Pop elements from the stack that are less
#       // than or equal to the current element
#       while (!stk.empty() && stk.top() <= arr[i]) {
#           stk.pop();
#       }
# 
#       // If the stack is not empty, the top element
#       // is the next greater element
#       if (!stk.empty()) {
#           res[i] = stk.top();
#       }
# 
#       // Push the current element onto the stack
#       stk.push(arr[i]);
#   }
# 
#   return res;
# }
# 
# int main() {
# 
#     vector<int> arr = {6, 8, 0, 1, 3};
#     vector<int> res = nextLargerElement(arr);
#     for (int x : res) {
#         cout << x << " ";
#     }
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
