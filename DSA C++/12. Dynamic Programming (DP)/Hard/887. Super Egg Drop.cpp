// You are given n identical eggs and you have access to a k-floored building from 1 to k.

// There exists a floor f where 0 <= f <= k such that any egg dropped from a floor higher than f will break, and any egg dropped from or below floor f will not break. There are a few rules given below:

//     An egg that survives a fall can be used again.
//     A broken egg must be discarded.
//     The effect of a fall is the same for all eggs.
//     If the egg doesn't break at a certain floor, it will not break at any floor below.
//     If the egg breaks on a certain floor, it will break on any floor above.

// Your task is to find the minimum number of moves you need to determine the value of f with certainty
// Example:

//     Input: n = 2, k = 36
//     Output: 8
//     Explanation: In all the situations, 8 maximum moves are required to find the maximum floor. Following is the strategy to do so:

//         Drop from floor 8 → If breaks, check 1-7 sequentially.
//         Drop from floor 15 → If breaks, check 9-14.
//         Drop from floor 21  → If breaks, check 16-20.
//         Drop from floor 26 → If breaks, check 22-25.
//         Drop from floor 30 → If breaks, check 27-29.
//         Drop from floor 33 → If breaks, check 31-32.
//         Drop from floor 35 → If breaks, check 34.
//         Drop from floor 36 → Final check.

//     Input: n = 1, k = 36
//     Output: 36
//     Explanation: Drop the egg from the first-floor window; if it survives, drop it from the second-floor window. Continue upward until it breaks. In the worst case, this method may require 36 droppings.

//     Input: n = 2, k = 10
//     Output: 4
//     Explanation: In all the situations, 4 maximum moves are required to find the maximum floor. Following is the strategy to do so:

//         Drop from floor 4 → If breaks, check 1-3 sequentially.
//         Drop from floor 7 → If breaks, check 5-6.
//         Drop from floor 9 → If breaks, check 8.
//         Drop from floor 10 → Final check.
#include <iostream>
#include <vector>
using namespace std;


int min_parachutes(int k, int n) {
  // Base cases
  if(n == 0) return 0;       // no floors
  if(n == 1) return 1;       // only one floor
  if(k == 1) return n;       // only one parachute: linear search

  int ans = INT_MAX;

  // Try dropping from all floors
  for(int x = 1; x <= n; x++) {
      int temp = 1 + max(
          min_parachutes(k-1, x-1), // breaks
          min_parachutes(k, n-x)    // survives
      );
      ans = min(ans, temp);
  }

  return ans;
}


int dp[51][1001]; // K <= 50, N <= 1000

int min_parachutes(int k, int n) {
    // Base cases
    if(n == 0) return 0;       // no floors
    if(n == 1) return 1;       // only one floor
    if(k == 1) return n;       // linear search with one parachute

    // Check memoization
    if(dp[k][n] != -1) return dp[k][n];

    int ans = INT_MAX;

    // Try dropping from all floors
    for(int x = 1; x <= n; x++) {
        int temp = 1 + max(
            min_parachutes(k-1, x-1), // breaks
            min_parachutes(k, n-x)    // survives
        );
        ans = min(ans, temp);
    }

    return dp[k][n] = ans; // store result
}

int main() {
    int n, k;
    cin >> n >> k;

    // Initialize dp array
    memset(dp, -1, sizeof(dp));

    int result = min_parachutes(k, n);
    cout << result << endl;

    return 0;
}
int min_parachutes(int k, int n) {
    // Edge cases
    if(n == 0) return 0;        // no floors
    if(k == 0) return 0;        // no parachutes
    if(k == 1) return n;        // linear search

    // dp[i] = max floors we can check with i parachutes
    vector<long long> dp(k + 1, 0);

    int moves = 0;

    while(dp[k] < n) {
        moves++;
        for(int i = k; i >= 1; i--) {
            dp[i] = dp[i] + dp[i - 1] + 1;
        }
    }

    return moves;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    int result = min_parachutes(k, n);
    cout << result << endl;

    return 0;
}