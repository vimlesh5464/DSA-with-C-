#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int h = n - mid;

            if (citations[mid] == h)
                return h;
            else if (citations[mid] < h)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return n - left;
    }
};

// 🔹 Driver Code
int main() {
    vector<int> citations = {0, 1, 3, 5, 6};
    Solution sol;
    cout << sol.hIndex(citations) << endl; // Output: 3
    return 0;
}
