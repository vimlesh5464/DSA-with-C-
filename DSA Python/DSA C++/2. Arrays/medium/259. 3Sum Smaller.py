# 259. 3Sum Smaller.py - Python skeleton converted from C++

# Original C++ code:
# // Given an array arr[] of distinct integers of size n and a value sum, the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.
# 
# // Examples :
# 
# // Input: n = 4, sum = 2, arr[] = {-2, 0, 1, 3}
# // Output:  2
# // Explanation: Below are triplets with sum less than 2 (-2, 0, 1) and (-2, 0, 3). 
# 
# // Input: n = 5, sum = 12, arr[] = {5, 1, 3, 4, 7}
# // Output: 4
# // Explanation: Below are triplets with sum less than 12 (1, 3, 4), (5, 1, 3), (1, 3, 7) and (5, 1, 4).
# 
# // Constraints:
# // 3 ≤ N ≤ 103
# // -103 ≤ arr[i] ≤ 103
# #include <iostream>
# #include<vector>
# using namespace std;
# 
# long long threeSumSmaller(vector<int>& nums, int target) {
#     sort(nums.begin(), nums.end());
#     int n = nums.size();
#     long long count = 0;
# 
#     for (int i = 0; i < n - 2; ++i) {
#         int l = i + 1;
#         int r = n - 1;
#         while (l < r) {
#             long long sum = (long long)nums[i] + nums[l] + nums[r];
#             if (sum < target) {
#                 // all indices between l and r with i form valid triplets
#                 count += (r - l);
#                 ++l;
#             } else {
#                 --r;
#             }
#         }
#     }
#     return count;
# }
# 
# int main() {
#     ios::sync_with_stdio(false);
#     cin.tie(nullptr);
# 
#     int n;
#     cout << "Enter number of elements: ";
#     if (!(cin >> n)) return 0;
# 
#     vector<int> nums(n);
#     cout << "Enter elements:\n";
#     for (int i = 0; i < n; ++i) cin >> nums[i];
# 
#     int target;
#     cout << "Enter target: ";
#     cin >> target;
# 
#     cout << "Number of triplets with sum < " << target << " is: "
#          << threeSumSmaller(nums, target) << "\n";
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
