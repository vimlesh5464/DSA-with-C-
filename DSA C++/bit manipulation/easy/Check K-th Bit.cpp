
// Given two positive integer n and  k, check if the kth index bit of n is set or not.
//  Note: A bit is called set if it is 1. 

// Examples : 

// Input: n = 4, k = 0
// Output: false
// Explanation: Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.

// Input: n = 4, k = 2
// Output: true
// Explanation: Binary representation of 4 is 100, in which 2nd index bit from LSB is set. So, return true.

// Input: n = 500, k = 3
// Output: false
// Explanation: Binary representation of 500 is 111110100, in which 3rd index bit from LSB is not set. So, return false.

// Constraints:
// 1 ≤ n ≤ 109
// 0 ≤ k ≤ 31
#include<iostream>
using namespace std;
// Time Complexity: O(log n), due to integer-to-binary conversion and indexing.

// Space Complexity: O(log n), for the binary string. 

class Solution {
public:
    // Function to check if the i-th bit of number n is set (1)
    bool checkIthBit(int n, int i) {
        string binary = "";
        // Convert the number into its binary representation
        while (n > 0) {
            binary += (n % 2 == 0 ? '0' : '1');  // Append '0' or '1' depending on the least significant bit
            n /= 2;  // Move to the next higher bit
        }

        // If the bit index is greater than the length of the binary string, the bit is 0
        if (i >= binary.size()) return false;

        // Return true if the i-th bit is 1, otherwise false
        return binary[i] == '1';
    }
};




// Time Complexity: O(1), constant time bitwise operation.

// Space Complexity: O(1), no additional space used. 

class Solution {
public:
    // Function to check if the i-th bit of number n is set (1)
    bool checkIthBit(int n, int i) {
        // Check if the i-th bit is set using bitwise AND operation
        return (n & (1 << i)) != 0;  // If the i-th bit is 1, the result will be non-zero
    }
};

int main() {
    Solution sol;
    int num = 5;  // Binary: 101
    int bitIndex = 2;  // Check the 2nd bit (0-based index)

    if (sol.checkIthBit(num, bitIndex)) {
        cout << "The " << bitIndex << "-th bit of " << num << " is set (1)." << endl;
    } else {
        cout << "The " << bitIndex << "-th bit of " << num << " is not set (0)." << endl;
    }

    return 0;
}
