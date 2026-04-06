// You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then return -1.

// Examples :

// Input: n = 3, m = 8
// Output: 2
// Explanation: 23 = 8

// Input: n = 3, m = 9
// Output: -1
// Explanation: 3rd root of 9 is not integer.

// Input: n = 4, m = 16
// Output: 2
// Explanation: 24 = 16

// Constraints:
// 1 ≤ n ≤ 9
// 0 ≤ m ≤ 20
#include<iostream>
#include <cmath>
using namespace std;

class Solution {
  public:
      int nthRoot(int n, int m) {
          // Edge case
          if (m == 0) return 0;
  
          for (int i = 1; i <= m; i++) {
              int val = 1;
  
              for (int j = 0; j < n; j++) {
                  val *= i;
              }
  
              if (val == m) return i;
          }
  
          return -1;
      }
  };
int nThroot(int n, int m){
  for(int i = 1; i <= m; i++){
    long long power = pow(i,n);
    if(power==m){
      return i;
    }
    if(power>m){
      break;
    }
  }
  return -1;
}

class Solution {
  public:
      // Helper function to compute (base^exp) safely
      long long power(int base, int exp, int m) {
          long long result = 1;
  
          for (int i = 0; i < exp; i++) {
              result *= base;
  
              if (result > m) return result; // early stop
          }
  
          return result;
      }
  
      int nthRoot(int n, int m) {
          // Edge case
          if (m == 0) return 0;
  
          int low = 1, high = m;
  
          while (low <= high) {
              int mid = low + (high - low) / 2;
  
              long long val = power(mid, n, m);
  
              if (val == m) return mid;
              else if (val < m) low = mid + 1;
              else high = mid - 1;
          }
  
          return -1;
      }
  };
int main(){
  Solution s;
  int n, m;
  cin>>n>>m;
  cout<<s.nthRoot(n,m);
  return 0;
}