
#include<iostream>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Fast exponentiation modulo MOD
    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; // positions 0,2,4...
        long long oddCount = n / 2;        // positions 1,3,5...
        long long ans = (modPow(5, evenCount) * modPow(4, oddCount)) % MOD;
        return ans;
    }
};

int main() {
    Solution sol;
    long long n;
    cout << "Enter the length of the number: ";
    cin >> n;
    cout << "Number of good numbers: " << sol.countGoodNumbers(n) << endl;
    return 0;
}
