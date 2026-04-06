# 85. Maximal Rectangle.py - Python skeleton converted from C++

# Original C++ code:
# // Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
# 
#  
# 
# // Example 1:
# 
# // Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
# // Output: 6
# // Explanation: The maximal rectangle is shown in the above picture.
# 
# // Example 2:
# 
# // Input: matrix = [["0"]]
# // Output: 0
# 
# // Example 3:
# 
# // Input: matrix = [["1"]]
# // Output: 1
# 
#  
# 
# // Constraints:
# 
# //     rows == matrix.length
# //     cols == matrix[i].length
# //     1 <= rows, cols <= 200
# //     matrix[i][j] is '0' or '1'.
# 
# #include <iostream>
# #include<vector>
# #include<stack>
# using namespace std;
# class Solution {
#   public:
#       int largestRectangleArea(vector<int> &heights) {
#           int n = heights.size();
#           stack<int> st;
#           int largestArea = 0;
#   
#           for(int i = 0; i < n; i++) {
#               while(!st.empty() && heights[st.top()] >= heights[i]) {
#                   int ind = st.top();
#                   st.pop();
#   
#                   int pse = st.empty() ? -1 : st.top();
#                   int nse = i;
#   
#                   largestArea = max(
#                       largestArea,
#                       heights[ind] * (nse - pse - 1)
#                   );
#               }
#               st.push(i);
#           }
#   
#           while(!st.empty()) {
#               int ind = st.top();
#               st.pop();
#   
#               int pse = st.empty() ? -1 : st.top();
#               int nse = n;
#   
#               largestArea = max(
#                   largestArea,
#                   heights[ind] * (nse - pse - 1)
#               );
#           }
#   
#           return largestArea;
#       }
#   
#       int maximalRectangle(vector<vector<char>>& matrix) {
#           if(matrix.empty()) return 0;
#   
#           int n = matrix.size();
#           int m = matrix[0].size();
#   
#           vector<vector<int>> prefixSum(n, vector<int>(m, 0));
#   
#           // Build histogram heights column-wise
#           for(int j = 0; j < m; j++) {
#               int height = 0;
#               for(int i = 0; i < n; i++) {
#                   if(matrix[i][j] == '1') {
#                       height++;
#                   } else {
#                       height = 0;
#                   }
#                   prefixSum[i][j] = height;
#               }
#           }
#   
#           int maxArea = 0;
#           for(int i = 0; i < n; i++) {
#               maxArea = max(
#                   maxArea,
#                   largestRectangleArea(prefixSum[i])
#               );
#           }
#   
#           return maxArea;
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
