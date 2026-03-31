// A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

// You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

// Display the number of indices where heights[i] != expected[i].

// Input Format

// An integer n representing the size of array

// N space separated integers representing elements of the array

// Output Format

//  An integer representing the number of indexes where expected[i] != height[i]

// Constraints

// 1 <= heights.length <= 100

// 1 <= heights[i] <= 100

 

// Sample Testcase 0

// Testcase Input
//  6
// 1 1 4 2 1 3
// Testcase Output
// 3
// Explanation

//  heights:  1 1 4 2 1 3
// expected: 1 1 1 2 3 4
// 3 indexes does not match index 2,4,5

// Sample Testcase 1

// Testcase Input
// 5
// 1 2 3 4 5
// Testcase Output
// 0
// Explanation

//   heights:  1 2 3 4 5
// expected: 1 2 3 4 5
// All indexes match hence our answer becomes 0


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int heightChecker(const vector<int>& heights) {
    vector<int> expected = heights;  // Make a copy of heights
    sort(expected.begin(), expected.end());  // Sort to get expected order

    int count = 0;
    for (int i = 0; i < heights.size(); i++) {
        if (heights[i] != expected[i]) {
            count++;  // Count indices where heights[i] != expected[i]
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << heightChecker(heights) << endl;

    return 0;
}