#include <iostream>
using namespace std;

class Solution {
public:
    // Function to compute sum of squares of digits
    int squareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    // Floyd's Cycle Detection Method
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = squareSum(slow);                // move 1 step
            fast = squareSum(squareSum(fast));     // move 2 steps
        } while (slow != fast);

        return slow == 1;  // if slow pointer meets 1 → it's a happy number
    }
};

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    Solution obj;
    if (obj.isHappy(n)) {
        cout << n << " is a Happy Number\n";
    } else {
        cout << n << " is NOT a Happy Number\n";
    }

    return 0;
}
