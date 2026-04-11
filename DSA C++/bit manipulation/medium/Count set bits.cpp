// You are given a number n. Find the total count of set bits for all numbers from 1 to n (both inclusive).

// Examples :

// Input: n = 4
// Output: 5
// Explanation: For numbers from 1 to 4. for 1: 0 0 1 => 1 set bit, for 2: 0 1 0 => 1 set bit, for 3: 0 1 1 => 2 set bits, for 4: 1 0 0 => 1 set bit. Therefore, the total set bits are 5.

// Input: n = 17
// Output: 35
// Explanation: From numbers 1 to 17(both inclusive), the total number of set bits are 35.

// Constraints:
// 1 ≤ n ≤ 108

#include <iostream>
#include <vector>
 using namespace std;
class Solution {
  public:
    int countSetBits(int n) {
        // code here
        if (n == 0) return 0;

        int x = log2(n);  // largest power of 2
        
        int bitsTill2x = x * (1 << (x - 1));   // bits from 1 to 2^x - 1
        int msb2xToN = n - (1 << x) + 1;       // MSB bits from 2^x to n
        int rest = n - (1 << x);               // remaining numbers

        return bitsTill2x + msb2xToN + countSetBits(rest);
    }
};
