# Nearest smaller numbers on left side in an array.py - Python skeleton converted from C++

# Original C++ code:
# // Given an array arr[] of integers, for each element in the array, find the nearest smaller
# // element on its left. If there is no such smaller element, return -1 for that position.
# 
# // Input: arr[] = [1, 6, 2]
# // Output: [-1, 1, 1]
# // Explaination: 
# // There is no number to the left of 1, so we return -1. 
# // After that, the number is 6, and the nearest smaller number on its left is 1. 
# // Next, the number is 2, and the nearest smaller number on the left is also 1.
# 
# // Input: arr[] = [1, 5, 0, 3, 4, 5]
# // Output: [-1, 1, -1, 0, 3, 4]
# // Explaination: 
# // There is no number to the left of 1,  so we return -1. 
# // After that, the number is 5,  and the nearest smaller number on its left is 1. 
# //  Next, the number is 0, and there is no smaller number on the left, so we return -1.
# // Then comes 3, and the nearest smaller number on its left is 0.
# // After that, the number is 4, and the nearest smaller number on the left is 3. 
# // Finally, the number is 5, and the nearest smaller number on its left is 4.
# 
# // Constraints:
# // 1 ≤ arr.size()≤ 106
# // 1 ≤ arr[i] ≤ 103
# //Nearest smaller numbers on left side in an array
# #include <iostream>
# #include <vector>
# #include<stack>
# using namespace std;
# 
# //[Naive Approach] Using Nested Loops - O(n^2) Time and O(1) Space
# vector<int> nearestSmallerToLeft(vector<int>& arr){
#     int n = arr.size();
#     vector<int> result(n, -1);
# 
#     // for each element, check all elements 
#     // on the left
#     for (int i = 0; i < n; i++) {
#         for (int j = i - 1; j >= 0; j--) {
#             if (arr[j] < arr[i]) {
#                 result[i] = arr[j];
#                 break;
#             }
#         }
#     }
#     return result;
# }
# 
# //[Expected Approach] Stack-based Approach (Monotonic stack)
# // Time Complexity: O(n), each element is pushed and popped at most once, so total stack operations are linear.
# // Auxiliary Space: O(n), in the worst case (strictly increasing array) the stack may hold all n elements.
# vector<int> nearestSmallerToLeft(vector<int>& arr) {
#   int n = arr.size();
#   vector<int> result(n, -1);
# 
#   // stack to keep track of elements
#   stack<int> s;
# 
#   // traverse the array from left to right
#   for (int i = 0; i < n; i++) {
#       // pop elements from stack until a smaller 
#       // element is found or stack becomes empty
#       while (!s.empty() && s.top() >= arr[i]) {
#           s.pop();
#       }
# 
#       // if stack is not empty, top is nearest smaller
#       if (!s.empty()) {
#           result[i] = s.top();
#       }
# 
#       // push current element to stack
#       s.push(arr[i]);
#   }
#   return result;
# }
# 
# int main() {
#     vector<int> arr = {1, 5, 0, 3, 4, 5};
#     vector<int> ans = nearestSmallerToLeft(arr);
# 
#     for (int x : ans) cout << x << " ";
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
