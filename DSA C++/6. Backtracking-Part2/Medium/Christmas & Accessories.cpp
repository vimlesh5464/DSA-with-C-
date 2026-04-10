// You have been provided with a ‘b’ number of bells, ‘c’ candies, and ‘a’ balloons, denoted by ‘B,’ ‘C,’ and ‘A’ respectively.

// Your task is to write a code that displays the different combinations of accessories that can be selected from the given set of bells, candies, and balloons to decorate your Christmas tree with exactly N accessories.

// Also, note the sequence of the selection has to be considered. The selection will be in the sequence B, C, and A.

// Input Format

// The first line contains an integer, where n denotes the number of accessories required for the celebration.

// The second line contains three space-separated  integers B , C and A.

 

// Output Format

// Print the combinations of accessories that can be selected from the given set in new lines.

// Constraints

// 1 ≤ N ≤ 10
// 0 ≤ a,b,c ≤ 20
// Sample Testcase 0

// Testcase Input
// 2 0 1 1
// Testcase Output
// CA
// AC
// Explanation

// There are two possible combinations in which 2 accessories could be selected out of 0 bells, 1 candy, and 1 balloon, which will be CA and AC.
// Sample Testcase 1

// Testcase Input
// 3 1 1 1
// Testcase Output
// BCA
// BAC
// CBA
// CAB
// ABC
// ACB
// Explanation

// There are two possible combinations in which 3 accessories could be selected out of 1 bell, 1 candy, and 1 balloon, which will be BCA, BAC, CBA, CAB, ABC, and ACB.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 🔹 Helper function (Backtracking)
void generate(int n, int b, int c, int a, string curr, vector<string> &result) {
    // base case
    if (curr.length() == n) {
        result.push_back(curr);
        return;
    }

    // Try B
    if (b > 0) {
        generate(n, b - 1, c, a, curr + 'B', result);
    }

    // Try C
    if (c > 0) {
        generate(n, b, c - 1, a, curr + 'C', result);
    }

    // Try A
    if (a > 0) {
        generate(n, b, c, a - 1, curr + 'A', result);
    }
}

vector<string> find_possible_combinations(int n, int b, int c, int a) {
    vector<string> result;
    
    generate(n, b, c, a, "", result);
    
    return result;
}

int main() {
    int n, b, c, a;
    cin >> n >> b >> c >> a;
    
    vector<string> result = find_possible_combinations(n, b, c, a);
    
    for (const string &combination : result) {
        cout << combination << endl;
    }
    
    return 0;
}