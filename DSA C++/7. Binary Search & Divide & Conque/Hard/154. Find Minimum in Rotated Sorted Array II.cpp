#include <iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high]) {
            // Minimum is in the right half
            low = mid + 1;
        } 
        else if (nums[mid] < nums[high]) {
            // Minimum is in the left half (including mid)
            high = mid;
        } 
        else {
            // nums[mid] == nums[high] -> can't decide, shrink high
            high--;
        }
    }

    return nums[low];
}

int main() {
    vector<int> nums = {2, 2, 2, 0, 1};
    cout << "Minimum element: " << findMin(nums) << endl;
    return 0;
}
