
#include <iostream>
#include<vector>
using namespace std;

long long threeSumSmaller(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long long count = 0;

    for (int i = 0; i < n - 2; ++i) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            long long sum = (long long)nums[i] + nums[l] + nums[r];
            if (sum < target) {
                // all indices between l and r with i form valid triplets
                count += (r - l);
                ++l;
            } else {
                --r;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) cin >> nums[i];

    int target;
    cout << "Enter target: ";
    cin >> target;

    cout << "Number of triplets with sum < " << target << " is: "
         << threeSumSmaller(nums, target) << "\n";

    return 0;
}
