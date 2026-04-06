# Maximum People Visible in a Lin.py - Python skeleton converted from C++

# Original C++ code:
# // You are given an array arr[ ], where arr[i] represents the height of the ith person standing in a line.
# // A person i can see another person j if:
# 
# //     height[j] < height[i],
# //     There is no person k standing between them such that height[k] ≥ height[i].
# 
# // Each person can see in both directions (front and back).
# // Your task is to find the maximum number of people that any person can see (including themselves).
# 
# // Examples:
# 
# // Input: arr[] = [6, 2, 5, 4, 5, 1, 6 ]
# // Output: 6
# // Explanation:
# // Person 1 (height = 6) can see five other people at following positions (2, 3, 4, 5. 6) in addition to himself, i.e. total 6.
# // Person 2 (height: 2) can see only himself.
# // Person 3 (height = 5) is able to see people 2nd, 3rd, and 4th person.
# // Person 4 (height = 4) can see himself.
# // Person 5 (height = 5) can see people 4th, 5th, and 6th.
# // Person 6 (height =1) can only see himself.
# // Person 7 (height = 6) can see 2nd, 3rd, 4th, 5th, 6th, and 7th people.
# // A maximum of six people can be seen by Person 1, 7th
# 
# // Input: arr[] = [1, 3, 6, 4]
# // Output: 4
# // Explanation: 
# // Person with height 6 can see persons with heights 1, 3 on the left and 4 on the right, along with himself, giving a total of 4.
# 
# // Constraints:
# // 1 ≤ arr.size() ≤ 104
# // 1 ≤ arr[i] ≤ 105
# #include<iostream>
# #include <vector>
# #include <stack>
# using namespace std;
# //leetcode version
# class Solution {
# public:
#     int maxPeople(std::vector<int>& arr) {
#         int n = arr.size();
#         if (n == 0) return 0;
#         
#         int maxVisible = 1;
#         
#         for (int i = 0; i < n; i++) {
#             int currentVisible = 1; // Including self
#             
#             // Look Right: Count consecutive elements smaller than arr[i]
#             for (int j = i + 1; j < n; j++) {
#                 if (arr[j] < arr[i]) {
#                     currentVisible++;
#                 } else {
#                     break; // Blocked by someone taller or equal
#                 }
#             }
#             
#             // Look Left: Count consecutive elements smaller than arr[i]
#             for (int j = i - 1; j >= 0; j--) {
#                 if (arr[j] < arr[i]) {
#                     currentVisible++;
#                 } else {
#                     break; // Blocked by someone taller or equal
#                 }
#             }
#             
#             maxVisible = max(maxVisible, currentVisible);
#         }
#         
#         return maxVisible;
#     }
# };
# 
# //gfg version
# class Solution {
#   public:
#       int maxPeople(vector<int> &arr) {
#           int n = arr.size();
#           if (n == 0) return 0;
#   
#           // nearestLeft[i] will store the index of the first person >= arr[i] to the left
#           vector<int> nearestLeft(n, -1);
#           // nearestRight[i] will store the index of the first person >= arr[i] to the right
#           vector<int> nearestRight(n, n);
#   
#           stack<int> s;
#   
#           // Find nearest larger or equal to the left
#           for (int i = 0; i < n; i++) {
#               while (!s.empty() && arr[s.top()] < arr[i]) {
#                   s.pop();
#               }
#               if (!s.empty()) {
#                   nearestLeft[i] = s.top();
#               }
#               s.push(i);
#           }
#   
#           // Clear stack for reuse
#           while(!s.empty()) s.pop();
#   
#           // Find nearest larger or equal to the right
#           for (int i = n - 1; i >= 0; i--) {
#               while (!s.empty() && arr[s.top()] < arr[i]) {
#                   s.pop();
#               }
#               if (!s.empty()) {
#                   nearestRight[i] = s.top();
#               }
#               s.push(i);
#           }
#   
#           int maxVisible = 0;
#           for (int i = 0; i < n; i++) {
#               // Count = (right_boundary - left_boundary - 1)
#               // Example: left index 0, right index 6, current index 3
#               // People seen are indices 1, 2, 3, 4, 5. Total = 6 - 0 - 1 = 5
#               int currentVisible = nearestRight[i] - nearestLeft[i] - 1;
#               maxVisible = max(maxVisible, currentVisible);
#           }
#   
#           return maxVisible;
#       }
#   };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
