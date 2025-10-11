#include <iostream>
#include<vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Solution {
  public:
      // Comparator function (must be static if inside the class)
      static bool compare(pair<double, int> a, pair<double, int> b) {
          return a.first > b.first; // Sort by ratio descending
      }
  
      double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
          int n = val.size();
          vector<pair<double, int>> ratio(n);
  
          // Step 1: Compute value/weight ratio
          for (int i = 0; i < n; i++) {
              double r = static_cast<double>(val[i]) / wt[i];
              ratio[i] = make_pair(r, i);
          }
  
          // Step 2: Sort by ratio (descending)
          sort(ratio.begin(), ratio.end(), compare);
  
          double ans = 0.0;
          int W = capacity;
  
          // Step 3: Pick items
          for (int i = 0; i < n; i++) {
              int idx = ratio[i].second;
  
              if (wt[idx] <= W) {
                  ans += val[idx];
                  W -= wt[idx];
              } else {
                  ans += ratio[i].first * W; // take fractional part
                  break;
              }
          }
  
          return ans;
      }
  };
  

int main() {
  Solution s;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;

    cout << "Maximum value in Knapsack = " << s.fractionalKnapsack(val, wt, W) << endl;

    return 0;
}
