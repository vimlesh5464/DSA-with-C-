#include<iostream>
using namespace std;
class Solution {
  public:
      double myPow(double x, int n) {
          // Convert n to long long to handle INT_MIN safely
          long long N = n;
          if (N < 0) {
              x = 1 / x;
              N = -N;
          }
          return fastPow(x, N);
      }
  
      double fastPow(double x, long long n) {
          if (n == 0) return 1.0;
  
          double half = fastPow(x, n / 2);
          if (n % 2 == 0)
              return half * half;
          else
              return half * half * x;
      }
  };
  
  class Solution {
    public:
        double myPow(double x, int n) {
            long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
    
        double result = 1.0;
        while (N > 0) {
            if (N % 2 == 1) {
                result *= x;
            }
            x *= x;
            N /= 2;
        }
    
        return result;
        }
    };