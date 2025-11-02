#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countSoldiers(vector<int>& row) {
        int low = 0, high = row.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == 1) 
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return low; // number of 1's
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> strength; // {soldier_count, row_index}

        for (int i = 0; i < mat.size(); i++) {
            int soldiers = countSoldiers(mat[i]);
            strength.push_back({soldiers, i});
        }

        sort(strength.begin(), strength.end()); // sort by soldier count, then index

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(strength[i].second);
        }

        return result;
    }
};

// 🔹 Driver code
int main() {
    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    int k = 3;

    Solution sol;
    vector<int> ans = sol.kWeakestRows(mat, k);

    cout << "Weakest " << k << " rows: ";
    for (int i : ans) cout << i << " ";
    cout << endl;
}
