#include <iostream>
#include <vector>
#include "max_subarray.h"
#include "min_subarray.h"
#include "max_circular_subarray.h"
#include "max_product_subarray.h"
using namespace std;

int main() {
    vector<int> nums;
    int n, x;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    cout << "Maximum Subarray Sum: " << maxSubArray(nums) << endl;
    cout << "Minimum Subarray Sum: " << minSubArray(nums) << endl;
    cout << "Maximum Circular Subarray Sum: " << maxCircularSubarraySum(nums) << endl;
    cout << "Maximum Product Subarray: " << maxProductSubarray(nums) << endl;

    return 0;
}
