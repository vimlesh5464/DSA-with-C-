// Problem Statement

// In a lively car showroom, an array of cars awaits, each with its distinctive features. 
//Picture yourself mixing and matching these cars in unique combinations to create dream 
//blends which has a F-score equal to the XOR value of the combination. 

// Your mission: To compute the blend score, which is the XOR of the F-score values for 
//all these dreamy combinations. 

// Now, it's time to reveal the grand total!

// Input Format

// The first line of input consists of the integer N – representing the number of cars 
//in the showroom.

// The second line consists of N integers - representing the features of the car. 

// Output Format

// Print the sum of F-score obtained.

// Constraints

// 1 <= N<= 10^4

// 0 <= Fi<= 10^4.

// Sample Testcase 0

// Testcase Input
// 5
// 4 3 5 1 2
// Testcase Output
// 3
// Explanation

// The xor of all the combinations possible is:


// 4 ^ (4^3) ^ (4^3^5) ^ (4^3^5^1) ^ (4^3^5^1^2) ^ (3) ^ (3^5) ^ (3^5^1) ^ (3^5^1^2) ^ (5) ^ (5^1) ^ (5^1^2) ^ (1) ^ (1^2) ^ 2 = 3
// Sample Testcase 1

// Testcase Input
// 4
// 1 4 5 2
// Testcase Output
// 0
// Explanation

// The xor of all the combinations possible is:


// 1 ^ (1^4) ^ (1^4^5) ^ (1^4^5^2) ^ (4) ^ (4^5) ^ (4^5^2) ^ (5) ^ (5^2) ^ 2 = 0
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    int result = 0;
    for (int i = 0; i < N; i++) {
        long long freq = (long long)(i + 1) * (N - i);
        if (freq % 2 == 1) {
            result ^= arr[i];
        }
    }

    cout << result << endl;
    return 0;
}