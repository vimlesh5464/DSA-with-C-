// A car company has projected its daily profit and loss for the next N days. 
//Each day's financial outcome is represented as an integer:

// A positive value indicates a profit.
// A negative value indicates a loss.
// Your task is to determine whether the sequence of profits and losses can be rearranged 
//such that, at no point during the N days, does the cumulative sum become zero. The 
//rearranged sequence must be in either non-decreasing or non-increasing order.

// Additionally, simply sorting the numbers is not enough—the chosen order must ensure 
//that no prefix sum of the sequence is ever zero. If one order fails, try the other order. 
//If neither order is valid, print "IMPOSSIBLE".

// If both orders satisfy the condition, print the order that starts with the larger 
//first element to ensure a deterministic output.

// Input Format

// The first line contains an integer N, denoting the number of days.

// The second line contains N integers representing the profit and loss for each day.

// Output Format

// Print “POSSIBLE” followed by the rearranged sequence if it is possible to meet the 
//condition. Otherwise, print “IMPOSSIBLE.”

// Constraints

// 1 ≤ N ≤ 100

// −50 ≤ Ai ≤ 50

// Sample Testcase 0

// Testcase Input
// 4
// 1 -1 2 -2
// Testcase Output
// IMPOSSIBLE
// Explanation

// No rearranged permutation can satisfy the condition
// Sample Testcase 1

// Testcase Input
// 7
// 2 3 1 4 5 -9 8
// Testcase Output
// POSSIBLE
// 8 5 4 3 2 1 -9
// Explanation

// Non-Decreasing Order: [-9, 1, 2, 3, 4, 5, 8]
// Prefix Sum Calculation: -9, -8, -6, -3, 1, 6, 14 (No zero)


// Non-Increasing Order: [8, 5, 4, 3, 2, 1, -9]
// Prefix Sum Calculation: 8, 13, 17, 20, 22, 23, 14 (No zero)


// Choosing the Order:
// Since both orders work, we select the one that starts with the larger first element:
// POSSIBLE

// 8 5 4 3 2 1 -9

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sort

bool isValid(std::vector<int> &v) {
    int sum = 0;
    for (int x : v) {
        sum += x;
        if (sum == 0) return false;
    }
    return true;
}

std::pair<std::string, std::vector<int>> user_logic(int n, std::vector<int> arr) {
    
    std::vector<int> inc = arr;
    std::vector<int> dec = arr;

    // Sort both ways
    std::sort(inc.begin(), inc.end());             // increasing
    std::sort(dec.rbegin(), dec.rend());           // decreasing

    bool ok1 = isValid(inc);
    bool ok2 = isValid(dec);

    if (!ok1 && !ok2) {
        return {"IMPOSSIBLE", {}};
    }

    // If both valid → choose one with larger first element
    if (ok1 && ok2) {
        if (dec[0] > inc[0]) {
            return {"POSSIBLE", dec};
        } else {
            return {"POSSIBLE", inc};
        }
    }

    // If only one works
    if (ok1) return {"POSSIBLE", inc};
    else return {"POSSIBLE", dec};
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    
    // Call user logic function
    auto result = user_logic(n, arr);
    
    // Print the output based on the result from user logic
    if (result.first == "IMPOSSIBLE") {
        std::cout << "IMPOSSIBLE" << std::endl;
    } else {
        std::cout << "POSSIBLE" << std::endl;
        for (const auto& num : result.second) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}