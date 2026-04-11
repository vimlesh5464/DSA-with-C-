// Given a positive integer n, write a function that returns the number of in its binary representation (also known as the Hamming weight).

 

// Example 1:

// Input: n = 11

// Output: 3

// Explanation:

// The input binary string 1011 has a total of three set bits.

// Example 2:

// Input: n = 128

// Output: 1

// Explanation:

// The input binary string 10000000 has a total of one set bit.

// Example 3:

// Input: n = 2147483645

// Output: 30

// Explanation:

// The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

 

// Constraints:

//     1 <= n <= 231 - 1

 
// Follow up: If this function is called many times, how would you optimize it?
#include<iostream>
using namespace std;
class Solution {
  public:
      int hammingWeight(int n) {
          int count = 0;
  
          while (n > 0) {
              if (n % 2 == 1) count++;
              n = n / 2;
          }
  
          return count;
      }
  };

//   Time Complexity: O(log n), because each bit of the integer is checked once.

// Space Complexity: O(1), only a few variables are used. 
  class Solution {
    public:
        // Function to count the number of set bits (1s) in the binary representation of n
        int countSetBits(int n) {
            int count = 0;  // Variable to store the count of set bits
    
            // Step 1: Count the number of set bits using bitwise operations
            while (n > 0) {
                count += (n & 1);  // Check if the least significant bit is set (1)
                n >>= 1;  // Right shift n by 1 to process the next bit
            }
    
            // Step 2: Return the count of set bits
            return count;
        }
    };

//   Time Complexity: O(k), where k is the number of set bits (often faster than checking all bits).

// Space Complexity: O(1), only a few variables are used. 
  class Solution {
    public:
      int setBits(int n) {
          // Write Your Code here
         int count = 0;  // Variable to store the count of set bits
  
          // Step 1: While n is non-zero, turn off the rightmost set bit
          while (n) {
              n &= (n - 1);  // Turn off the rightmost set bit
              count++;  // Increment the count
          }
  
          // Step 2: Return the count of set bits
          return count;
      }
  };