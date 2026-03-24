// Given an integer n, we need to repeatedly find the sum of its digits until the result becomes a single-digit number.
// Examples:

//     Input: n = 1234 
//     Output: 1 
//     Explanation:
//     Step 1: 1 + 2 + 3 + 4 = 10 
//     Step 2: 1 + 0 = 1

//     Input: n = 5674
//     Output: 4
//     Explanation: 
//     Step 1: 5 + 6 + 7 + 4 = 22 
//     Step 2: 2 + 2 = 4

#include <iostream>
using namespace std;

//[Naive Approach] By Repetitively Adding Digits

// Time Complexity: O(log10n), as we are iterating over the digits of the number.
// Auxiliary Space: O(1)
int singleDigit(int n) {
    int sum = 0;

    // Repetitively calculate sum until
    // it becomes single digit
    while (n > 0 || sum > 9) {

        // If n becomes 0, reset it to sum 
        // and start a new iteration.
        if (n == 0) {
            n = sum;
            sum = 0;
        }

        sum += n % 10;
        n /= 10;
    }
    return sum;
}

//[Expected Approach] Using Mathematical Formula

int main() {
    int n = 1234;
    cout << singleDigit(n);
    return 0;
}