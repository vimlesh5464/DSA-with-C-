// A digit string is good if the digits (0-indexed) at even indices are 
//even and the digits at odd indices are prime (2, 3, 5, or 7).

//     For example, "2582" is good because the digits (2 and 8) at even positions
// are even and the digits (5 and 2) at odd positions are prime. However, 
//"3245" is not good because 3 is at an even index but is not even.

// Given an integer n, return the total number of good digit strings of 
//length n. Since the answer may be large, return it modulo 109 + 7.

// A digit string is a string consisting of digits 0 through 9 that may 
//contain leading zeros.

 

// Example 1:

// Input: n = 1
// Output: 5
// Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

// Example 2:

// Input: n = 4
// Output: 400

// Example 3:

// Input: n = 50
// Output: 564908303

 

// Constraints:

//     1 <= n <= 1015

#include<iostream>
using namespace std;
class Solution {
  public:
      // Mod value to prevent overflow and keep result within limits
      const int MOD = 1e9 + 7;
  
      // Fast exponentiation (Binary Exponentiation)
      // Computes (base^exp) % MOD efficiently in O(log exp)
      long long modPow(long long base, long long exp) {
          long long result = 1;
  
          while (exp > 0) {
              // If exponent is odd, multiply current base with result
              if (exp % 2 == 1) 
                  result = (result * base) % MOD;
  
              // Square the base
              base = (base * base) % MOD;
  
              // Divide exponent by 2
              exp /= 2;
          }
  
          return result;
      }
  
      int countGoodNumbers(long long n) {
          // Even indices (0-based): 0,2,4...
          // Each can have 5 choices → {0,2,4,6,8}
          long long evenCount = (n + 1) / 2;
  
          // Odd indices: 1,3,5...
          // Each can have 4 choices → {2,3,5,7}
          long long oddCount = n / 2;
  
          // Total ways:
          // (5 ^ evenCount) * (4 ^ oddCount)
          // Use modPow to handle large powers efficiently
          long long ans = (modPow(5, evenCount) * modPow(4, oddCount)) % MOD;
  
          return ans;
      }
  };

int main() {
    Solution sol;
    long long n;
    cout << "Enter the length of the number: ";
    cin >> n;
    cout << "Number of good numbers: " << sol.countGoodNumbers(n) << endl;
    return 0;
}
