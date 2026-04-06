# Print All Subarrays.py - Python skeleton converted from C++

# Original C++ code:
# // Given an array, arr[], generate all possible subarrays using recursion and return them as a vector of vectors.
# // The subarrays must be returned in the following order:
# //       1. Subarrays starting from the first element, followed by subarrays starting from the second element, and so on.
# //       2. For each starting index, subarrays should be in increasing length.
# 
# // Examples: 
# 
# // Input: arr[] = [1, 2, 3]
# // Output: [[1], [1, 2], [1, 2, 3], [2], [2, 3], [3]]
# // Explanation: Starting with the first element, we generate subarrays [1], [1, 2], and [1, 2, 3]. Then, starting from the second element, we get [2] and [2, 3].  Finally, starting from the third element, we only get [3].
# 
# // Input: arr[] = [1, 2]
# // Output: [[1], [1, 2], [2]]
# // Explanation: Starting with the first element, we generate subarrays [1] and [1, 2]. Then, starting from the second element, we get [2].
# 
# // Input: arr[] = [1, 1]
# // Output: [[1], [1, 1], [1]]
# // Explanation: Starting with the first element, we generate subarrays [1] and [1, 1] (including both elements). Starting from the second element, we only get the subarray [1].
# 
# // Constraints:
# // 1 <= arr.size() <= 103
# // 1 <= arr[i] <= 106
# 
# #include <iostream>
# #include <vector>
# 
# using namespace std;
# 
# vector<vector<int>> storeAllSubarrays(vector<int>& arr) {
#   int n = arr.size();
#   vector<vector<int>> result;
# 
#   for (int start = 0; start < n; start++) {
#       for (int end = start; end < n; end++) {
#           vector<int> subarray;
#           for (int i = start; i <= end; i++) {
#               subarray.push_back(arr[i]);
#           }
#           result.push_back(subarray);
#       }
#   }
#   return result;
# }
# 
# 
# 
# vector<vector<int>> allSubarrays(vector<int>& arr) {
#   int n = arr.size();
#   vector<vector<int>> result;
# 
#   for (int i = 0; i < n; i++) {
#       vector<int> temp;
#       for (int j = i; j < n; j++) {
#           temp.push_back(arr[j]);
#           result.push_back(temp);
#       }
#   }
#   return result;
# }
# 
# int totalSubarrays(int n) {
#   return n * (n + 1) / 2;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
