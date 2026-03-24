// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000

// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100

// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

 

// Constraints:

//     -100.0 < x < 100.0
//     -231 <= n <= 231-1
//     n is an integer.
//     Either x is not zero or n > 0.
//     -104 <= xn <= 104

#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;
//1. Brute Force
// Time Complexity: O(n)
// Space Complexity: O(1)
double myPow(double x, int n) {
    double result = 1.0;
    long long N = n; // handle negative n
    if(N < 0) { 
        x = 1/x;
        N = -N;
    }
    for(long long i = 0; i < N; i++)
        result *= x;
    return result;
}
class Solution {
  double myPow(double x, int n) {
    double result = 1.0;
    long long N = n; // handle negative n
    if(N < 0) { 
        x = 1/x;
        N = -N;
    }
    for(long long i = 0; i < N; i++)
        result *= x;
    return result;
}

};
//2. Fast Power (Exponentiation by Squaring) ✅
//Time Complexity: O(log n)
//Space Complexity:O(1)
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  // to handle INT_MIN
        if(N < 0) {
            x = 1/x;
            N = -N;
        }
        double result = 1.0;
        while(N > 0) {
            if(N % 2 == 1) result *= x; // multiply when n is odd
            x *= x;  // square the base
            N /= 2;  // divide exponent by 2
        }
        return result;
    }
};

int main() {
    Solution s;
    double x = 2.00000;
    int n = -2;
    cout << "Pow(x, n): " << s.myPow(x, n) << endl;
    return 0;
}
