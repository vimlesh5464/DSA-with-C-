# 56. Merge Intervals.py - Python skeleton converted from C++

# Original C++ code:
# // Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
# 
#  
# 
# // Example 1:
# 
# // Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
# // Output: [[1,6],[8,10],[15,18]]
# // Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
# 
# // Example 2:
# 
# // Input: intervals = [[1,4],[4,5]]
# // Output: [[1,5]]
# // Explanation: Intervals [1,4] and [4,5] are considered overlapping.
# 
# // Example 3:
# 
# // Input: intervals = [[4,7],[1,4]]
# // Output: [[1,7]]
# // Explanation: Intervals [1,4] and [4,7] are considered overlapping.
# 
#  
# 
# // Constraints:
# 
# //     1 <= intervals.length <= 104
# //     intervals[i].length == 2
# //     0 <= starti <= endi <= 104
# 
# #include <vector>
# #include <iostream>
# using namespace std;
# 
# class Solution {
#   public:
#       vector<vector<int>> merge(vector<vector<int>>& intervals) {
#           int n = intervals.size(); // size of the array
#   
#       //sort the given intervals:
#       sort(intervals.begin(), intervals.end());
#   
#       vector<vector<int>> ans;
#   
#       for (int i = 0; i < n; i++) {
#           // if the current interval does not
#           // lie in the last interval:
#           if (ans.empty() || intervals[i][0] > ans.back()[1]) {
#               ans.push_back(intervals[i]);
#           }
#           // if the current interval
#           // lies in the last interval:
#           else {
#               ans.back()[1] = max(ans.back()[1], intervals[i][1]);
#           }
#       }
#       return ans;
#       }
#   };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
