// Given a positive integer num, return true if num is a perfect square or false otherwise.

// A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

// You must not use any built-in library function, such as sqrt.

 

// Example 1:

// Input: num = 16
// Output: true
// Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

// Example 2:

// Input: num = 14
// Output: false
// Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.

 

// Constraints:

//     1 <= num <= 231 - 1

 
class Solution {
  public:
      bool isPerfectSquare(int num) {
          long long i = 1;
  
          while(i * i <= num) {
              if(i * i == num) {
                  return true;
              }
              i++;
          }
  
          return false;
      }
  };
#include<iostream>
using namespace std;
bool valid_perfect_square(int n){
  int l = 0, h = n;
  while(l<=h){
    int mid = l + (h-l)/2;
    if(mid*mid==n){
      return true;
    }else if(mid*mid<n){
      l = mid+1;
    }else{
      h = mid-1;
    }
  }
  return false;
}

int main(){
  int n;
  cin>> n;
  cout<<valid_perfect_square(n);
  return 0;
}