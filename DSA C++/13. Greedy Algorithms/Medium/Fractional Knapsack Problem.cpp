// Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
// Return the maximum value as a double, rounded to 6 decimal places.

// Examples :

// Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
// Output: 240.000000
// Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240

// Input: val[] = [500], wt[] = [30], capacity = 10
// Output: 166.670000
// Explanation: Since the item’s weight exceeds capacity, we take a fraction 10/30 of it, yielding value 166.670000.

// Constraints:
// 1 ≤ val.size = wt.size ≤ 105
// 1 ≤ capacity ≤ 109
// 1 ≤ val[i], wt[i] ≤ 104
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
