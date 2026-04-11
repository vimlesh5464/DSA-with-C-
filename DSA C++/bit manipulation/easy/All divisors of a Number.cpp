// Given an integer n, print all the divisors of N in the ascending order.
 
// Examples:

// Input : n = 20
// Output: 1 2 4 5 10 20
// Explanation: 20 is completely divisible by 1, 2, 4, 5, 10 and 20.

// Input: n = 21191
// Output: 1 21191
// Explanation: As 21191 is a prime number, it has only 2 factors(1 and the number itself).

// Constraints:
// 1 ≤ n ≤ 109

 
#include<iostream>
using namespace std;
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int> small, large;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            small.push_back(i);

            if (i != n / i) {   // avoid duplicate for perfect square
                large.push_back(n / i);
            }
        }
    }

    // print in ascending order
    for (int x : small) {
        cout << x << " ";
    }

    for (int i = large.size() - 1; i >= 0; i--) {
        cout << large[i] << " ";
    }
    }
};