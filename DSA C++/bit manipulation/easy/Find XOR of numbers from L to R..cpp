// You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

// Example:

// Input: 
// L = 4, R = 8 
// Output:
// 8 
// Explanation:
// 4 ^ 5 ^ 6 ^ 7 ^ 8 = 8

// Your Task:

// Your task is to complete the function findXOR() which takes two integers l and r and returns the XOR of numbers from l to r.

// Expected Time Complexity: O(1).

// Expected Auxiliary Space: O(1).

// Constraints:

// 1<=l<=r<=109

// User function Template for C++
#include<iostream>
using namespace std;

// Time Complexity: O(N) Traversing through all the numbers take O(N) time.

// Space Complexity: O(1) Using only a couple of variables, i.e., constant space. 
class Solution {
  public:
  
      /* Function to find the XOR 
      of numbers from L to R*/
      int findRangeXOR(int l, int r){			
          
          // To store the XOR of numbers
      int ans = 0;
      
      // XOR all the numbers
      for(int i=l; i <= r; i++) {
          ans ^= i;
      }
      
      // Return the result
      return ans;
    }
  };
  


// Time Complexity: O(1) Using constant time operations.

// Space Complexity: O(1) Using a couple of variables i.e., constant space. 
class Solution {
  public:
  int XORtillN(int n) {
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n+1;
        if(n % 4 == 3) return 0;
        return n;
    }
  
    int findXOR(int l, int r) {
        // complete the function here
        return XORtillN(l-1) ^ XORtillN(r);
    }
};