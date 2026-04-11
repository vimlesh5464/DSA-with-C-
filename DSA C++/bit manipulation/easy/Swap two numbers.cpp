// You are given two numbers a and b. Your task is to swap the given two numbers.

// Note: Try to do it without a temporary variable.

// Examples:

// Input: a = 13, b = 9
// Output: 9 13
// Explanation: After swapping it becomes 9 and 13.

// Input: a = 15, b = 8
// Output: 8 15
// Explanation: after swapping it becomes 8 and 15.

// Constraints:
// 1 ≤ a, b ≤ 106
#include<iostream>
using namespace std;
// Time Complexity: O(1) Constant operations.

// Space Complexity: O(1) No extra space used. 
class Solution {
  public:
      pair<int, int> get(int a, int b) {
          // Step 1: XOR a and b, store in a
    a = a ^ b;

    // Step 2: XOR new a with b, result is original a → store in b
    b = a ^ b;

    // Step 3: XOR new a with new b, result is original b → store in a
    a = a ^ b;
  
          return {a, b};  // ✅ return swapped values
      }
  };