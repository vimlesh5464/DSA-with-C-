// Given an array of intervals where intervals[i] = [starti, endi],
// merge all overlapping intervals, and return an array of the non-overlapping 
//intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

// Example 3:

// Input: intervals = [[4,7],[1,4]]
// Output: [[1,7]]
// Explanation: Intervals [1,4] and [4,7] are considered overlapping.

 

// Constraints:

//     1 <= intervals.length <= 104
//     intervals[i].length == 2
//     0 <= starti <= endi <= 104

 
// Approaches
// 1. Brute Force (Not Efficient)
// Compare every pair of intervals.
// Merge if overlapping.
// Repeat until no more merges.
// Time Complexity: O(n²)
// Space Complexity: O(n)
//Not recommended for large inputs.
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  bool merged;
  do {
      merged = false;
      for(int i = 0; i < intervals.size(); i++) {
          for(int j = i+1; j < intervals.size(); j++) {
              // Check overlap
              if(intervals[i][1] >= intervals[j][0] && intervals[i][0] <= intervals[j][1]) {
                  // Merge
                  intervals[i][0] = min(intervals[i][0], intervals[j][0]);
                  intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                  intervals.erase(intervals.begin() + j); // remove merged interval
                  merged = true;
                  break;
              }
          }
          if(merged) break;
      }
  } while(merged);
  return intervals;
}


// 🔹 Approach 1: Sorting + Merge (Optimal) ✅Idea:
// Sort intervals based on start times.
// Initialize a merged vector.
// For each interval:
// If it does not overlap with the last interval in merged, add it.
// Else, merge it by updating the end time.
// Time Complexity: O(n log n) → sorting dominates
// Space Complexity: O(n) → for output

#include <iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
  public:
      vector<vector<int>> merge(vector<vector<int>>& intervals) {
          int n = intervals.size(); // size of the array
  
      //sort the given intervals:
      sort(intervals.begin(), intervals.end());
  
      vector<vector<int>> ans;
  
      for (int i = 0; i < n; i++) {
          // if the current interval does not
          // lie in the last interval:
          if (ans.empty() || intervals[i][0] > ans.back()[1]) {
              ans.push_back(intervals[i]);
          }
          // if the current interval
          // lies in the last interval:
          else {
              ans.back()[1] = max(ans.back()[1], intervals[i][1]);
          }
      }
      return ans;
      }
  };
int main() {
    Solution s;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    
    vector<vector<int>> res = s.merge(intervals);

    cout << "Merged Intervals: ";
    for(auto &interval : res){
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    return 0;
}
