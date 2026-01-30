#include <iostream>
#include<vector>
using namespace std;
// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        int n = bt.size();
    sort(bt.begin(), bt.end());  // Sort burst times (Shortest Job First)

    long long total_wt = 0;     // total waiting time
    long long prev_sum = 0;     // cumulative sum of burst times

    for(int i = 0; i < n; i++) {
        total_wt += prev_sum;   // waiting time for current process
        prev_sum += bt[i];      // add current burst to cumulative sum
    }

    return total_wt / n;        // floor division as required
    }
};