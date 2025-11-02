#include <iostream>
#include <vector>
#include <climits>     // for INT_MAX
#include <algorithm>   // for max(), min(), etc.
#include <cmath>       // for ceil(), abs(), pow()
using namespace std;

// Mock API class (as in LeetCode problem)
class ArrayReader {
public:
    vector<int> arr;

    ArrayReader(vector<int> &nums) { arr = nums; }

    int get(int index) const {   // ✅ make this const
        if (index >= arr.size()) return INT_MAX;
        return arr[index];
    }
};

class Solution {
public:
    int search(const ArrayReader &reader, int target) {
        int low = 0;
        int high = 1;

        // 🔹 Step 1: Find search boundary
        while (reader.get(high) < target) {
            low = high;
            high = high * 2;
        }

        // 🔹 Step 2: Binary search within [low, high]
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = reader.get(mid);

            if (val == target) return mid;
            else if (val > target) high = mid - 1;
            else low = mid + 1;
        }

        return -1;
    }
};

// 🔹 Driver code
int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12, 15, 20, 25, 30};
    ArrayReader reader(nums);
    Solution sol;

    int target = 9;
    cout << sol.search(reader, target) << endl;  // ✅ Output: 4
    return 0;
}
