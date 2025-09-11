// Approaches
// 1. Brute Force (Not Efficient)
// Compare every pair of intervals.
// Merge if overlapping.
// Repeat until no more merges.
// Time Complexity: O(n²)
// Space Complexity: O(n)
//Not recommended for large inputs.


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
