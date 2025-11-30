#include "max_circular_subarray.h"
#include "max_subarray.h"
#include "min_subarray.h"
#include <algorithm>

int maxCircularSubarraySum(vector<int>& nums) {
    int total_sum = 0;
    for(int i = 0; i < nums.size(); i++) total_sum += nums[i];

    int max_kadane = maxSubArray(nums);
    int min_sum = minSubArray(nums);

    int max_wrap = total_sum - min_sum;

    return (max_wrap == 0) ? max_kadane : max(max_kadane, max_wrap);
}
