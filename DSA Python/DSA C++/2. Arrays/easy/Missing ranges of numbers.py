# Missing ranges of numbers.py - Python skeleton converted from C++

# Original C++ code:
# // You have an inclusive interval [lower, upper] and a sorted array of unique integers arr[], all of which lie within this interval. A number x is considered missing if x is in the range [lower, upper] but not present in arr. Your task is to return the smallest set of sorted ranges that includes all missing numbers, ensuring no element from arr is within any range, and every missing number is covered exactly once.
# 
# // Examples
# 
# //     Input: arr[] = [14, 15, 20, 30, 31, 45], lower = 10, upper = 50
# //     Output: [[10, 13], [16, 19], [21, 29], [32, 44], [46, 50]]
# //     Explanation: These ranges represent all missing numbers between 10 and 50 not present in the array
# 
# //     Input: arr[] = [-48, -10, -6, -4, 0, 4, 17], lower = -54, upper = 17
# //     Output: [[-54, -49], [-47, -11], [-9, -7], [-5, -5], [-3, -1], [1, 3], [5,16]]
# //     Explanation: These ranges represent all missing numbers between -54 and 17 not present in the array.
# #include <iostream>
# #include <vector>
# using namespace std;
# 
# //Using Linear Scan - O(n) Time and O(1) Space
# vector<vector<int>> missingRanges(vector<int> &arr, int lower, int upper) {
#     int n = arr.size();
#     vector<vector<int>> res;
# 
#     // Check for missing range before the first element
#     if (lower < arr[0])
#         res.push_back({lower, arr[0] - 1});
# 
#     // Check for missing ranges between consecutive elements
#     for (int i = 0; i < n - 1; ++i)
#         if (arr[i + 1] - arr[i] > 1)
#             res.push_back({arr[i] + 1, arr[i + 1] - 1});
# 
#     // Check for missing range after the last element
#     if (n > 0 && upper > arr[n - 1])
#         res.push_back({arr[n - 1] + 1, upper});
# 
#     return res;
# }
# 
# int main() {
#     int lower = 10, upper = 50;
#     vector<int> arr{14, 15, 20, 30, 31, 45};
#     vector<vector<int>> res = missingRanges(arr, lower, upper);
#     for (const vector<int> &v : res)
#         cout << v[0] << " " << v[1] << endl;
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
