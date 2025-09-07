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
