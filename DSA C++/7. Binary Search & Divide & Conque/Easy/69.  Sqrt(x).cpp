// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

//     For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

 

// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.

// Example 2:

// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

 

// Constraints:

//     0 <= x <= 231 - 1

#include<iostream>
using namespace std;
class Solution {
  public:
      int mySqrt(int x) {
          long long i = 0;
  
          while(i * i <= x) {
              i++;
          }
  
          return i - 1; // last valid value
      }
  };


int sqrt(int x){
  long long l = 0, h = x, ans = 0;
  while(l<=h){
    long long mid = l + (h-l)/2;
    if(mid*mid<=x){
      ans = mid;
      l = mid +1;
    }else{
      h = mid-1;
    }
  }
  return ans;
}

int main(){
  int x;
  cin>> x;
  cout<< sqrt(5);
  return 0;
}