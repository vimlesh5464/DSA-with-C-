#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
  
      int eraseOverlapIntervals(vector<vector<int>>& intervals) {
          if (intervals.empty()) return 0;
  
          // Sort intervals by end time
          sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
              return a[1] < b[1];
          });
  
          int count = 1; // at least one interval is always non-overlapping
          int currEnd = intervals[0][1];
  
          // Count non-overlapping intervals (activity selection logic)
          for (int i = 1; i < intervals.size(); i++) {
              if (intervals[i][0] >= currEnd) {
                  count++;
                  currEnd = intervals[i][1];
              }
          }
  
          // To make all intervals non-overlapping, remove the rest
          return intervals.size() - count;
      }
  };
  int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << sol.eraseOverlapIntervals(intervals) << endl; // Output: 1
}
