// Given a number n. Find its unique prime factors in increasing order.

// Examples :

// Input: n = 100
// Output: [2, 5]
// Explanation: Unique prime factors of 100 are 2 and 5.

// Input: n = 60
// Output: [2, 3, 5]
// Explanation: Prime factors of 60 are 2, 2, 3, 5. Unique prime factors are 2, 3 and 5.

// Constraints:
// 1 ≤ n ≤ 106
#include<iostream>
using namespace std;
class Solution {
  public:
      vector<int> primeFac(int n) {
          vector<int> result;
  
          // Step 1: handle 2
          if(n % 2 == 0) {
              result.push_back(2);
              while(n % 2 == 0) {
                  n /= 2;
              }
          }
  
          // Step 2: check odd numbers
          for(int i = 3; i * i <= n; i += 2) {
              if(n % i == 0) {
                  result.push_back(i);
                  while(n % i == 0) {
                      n /= i;
                  }
              }
          }
  
          // Step 3: if remaining n is prime
          if(n > 1) {
              result.push_back(n);
          }
  
          return result;
      }
  };