// C++ program to find the digit sum by 
// repetitively Adding its digits

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