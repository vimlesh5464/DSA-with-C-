
#include<iostream>
#include<cmath>
using namespace std;
class Solution {
  public:
      bool isPowerOfTwo(int n) {
          if (n <= 0) return false;
          while (n % 2 == 0) {
              n /= 2;
          }
          return n == 1;
      }
  };

  class Solution {
    public:
        bool isPowerOfTwo(int n) {
            if (n <= 0) return false;
            return (n & (n - 1)) == 0;
        }
    };
    class Solution {
      public:
          bool isPowerOfTwo(int n) {
              if(n <= 0) return false;
              double x = log2(n);
              return floor(x) == x;
          }
      };