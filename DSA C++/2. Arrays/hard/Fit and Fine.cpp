// Three characteristics of N food items are represented in three arrays classified as fat, protein, and vitamin. There are three categories of people, first who needs only that food which is rich in fat but with no protein and vitamins, a second who needs only that food which is rich in protein but with no fat and vitamin, and lastly, who needs only that food which is rich in vitamin but with no protein and fat. Write a program to return the number of food items eligible for the three categories.

// Input Format

// The input consists of four lines. The first line contains a single integer N. The second line contains N space-separated integers denoting the array fat[]. The third line contains N space-separated integers denoting the array protien[]. The fourth line contains N space-separated integers denoting the array vitamin[].

// Output Format

// Print three space-separated numbers.

// Constraints

// 1 ≤ N ≤ 10^2
// 1 ≤ arr[I] ≤10^2
// Sample Testcase 0

// Testcase Input
// 3
// 1 2 3
// 3 4 5
// 2 4 5
// Testcase Output
// 1 0 0
// Explanation

// From array fat, there is a single element, i.e., 1, which is not in array protein and vitamin. For protein and vitamins many elements are present only in protein and vitamins. So, the answer is 1 0 0.
// Sample Testcase 1

// Testcase Input
// 4
// 1 2 3 4
// 5 6 7 8
// 9 9 9 9
// Testcase Output
// 4 4 4
// Explanation

// In all three arrays, elements are unique, meaning they don't occur in any arrays other than theirs. Hence the answer is 4, 4, 4. 
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> user_logic(vector<int> &fat, vector<int> &protein, vector<int> &vitamin) {
    
    unordered_set<int> proteinSet(protein.begin(), protein.end());
    unordered_set<int> vitaminSet(vitamin.begin(), vitamin.end());
    unordered_set<int> fatSet(fat.begin(), fat.end());

    int fatCount = 0, proteinCount = 0, vitaminCount = 0;

    // Count for fat (use original array, not set)
    for (int x : fat) {
        if (proteinSet.find(x) == proteinSet.end() && vitaminSet.find(x) == vitaminSet.end()) {
            fatCount++;
        }
    }

    // Count for protein
    for (int x : protein) {
        if (fatSet.find(x) == fatSet.end() && vitaminSet.find(x) == vitaminSet.end()) {
            proteinCount++;
        }
    }

    // Count for vitamin
    for (int x : vitamin) {
        if (fatSet.find(x) == fatSet.end() && proteinSet.find(x) == proteinSet.end()) {
            vitaminCount++;
        }
    }

    return {fatCount, proteinCount, vitaminCount};
}

int main() {
    int n;
    cin >> n;

    vector<int> fat(n), protein(n), vitamin(n);

    for (int i = 0; i < n; ++i) cin >> fat[i];
    for (int i = 0; i < n; ++i) cin >> protein[i];
    for (int i = 0; i < n; ++i) cin >> vitamin[i];

    vector<int> result = user_logic(fat, protein, vitamin);

    cout << result[0] << " " << result[1] << " " << result[2] << endl;

    return 0;
}