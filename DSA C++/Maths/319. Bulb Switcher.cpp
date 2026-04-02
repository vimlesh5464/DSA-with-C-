// You have M coins placed on the floor, all initially showing tails.

// In the first round, you flip all the coins to heads.
// In the second round, you flip every second coin that is currently showing heads, turning it to tails.
// In the third round, you flip every third coin, toggling it between heads and tails.
// In the ith round, you flip every ith coin.
// After performing this for M rounds, where in the last round you only flip the Mth coin, determine how many coins are showing heads.

// Input Format

// The first line contains an integer M representing the number of coins.

// Output Format

// Print the number of coins that are showing heads after M rounds.

// Constraints

//  0 <= M <= 10^4

// Sample Testcase 0

// Testcase Input
// 3
// Testcase Output
// 1
// Explanation

// At first, the three Coins are [tail, tail, tail].


// After the first round, the three Coins are [head, head, head].


// After the second round, the three Coins are [head, tail, head].


// After the third round, the three Coins are [head, tail, tail]. 


// So you should Print 1 because there is only one Coin left with the head.
// Sample Testcase 1

// Testcase Input
// 0
// Testcase Output
// 0
// Explanation

// No Coin no head
#include <iostream>
using namespace std;

int find(int m) {
  if(m==0){
      return 0;
  }
  
  return floor(sqrt(m));
}

int main() {
    int m;
    cin >> m;

    // Step 1: Initialize all coins as tail (0)
    vector<int> coins(m, 0);

    // Step 2: Perform rounds
    for (int i = 1; i <= m; i++) {
        for (int j = i - 1; j < m; j += i) {
            coins[j] = 1 - coins[j]; // toggle (0->1, 1->0)
        }
    }

    // Step 3: Count heads
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (coins[i] == 1) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}