# Count Subarrays with given XOR.py - Python skeleton converted from C++

# Original C++ code:
# // Given an array of integers arr[] and a number k, count the number of subarrays
# // having XOR of their elements as k.
# 
# // Note: It is guranteed that the total count will fit within a 32-bit integer.
# 
# // Examples: 
# 
# // Input: arr[] = [4, 2, 2, 6, 4], k = 6
# // Output: 4
# // Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.
# 
# // Input: arr[] = [5, 6, 7, 8, 9], k = 5
# // Output: 2
# // Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.
# 
# // Input: arr[] = [1, 1, 1, 1], k = 0
# // Output: 4
# // Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].
# 
# // Constraints:
# // 1 ≤ arr.size() ≤ 105
# // 0 ≤ arr[i] ≤ 105
# // 0 ≤ k ≤ 105
# #include<iostream>
# #include <vector>
# #include <unordered_map>
# using namespace std;
# 
# class Solution {
#   public:
#     long scountSubarraysXOR(vector<int> &A, int B) {
#         // code here
#         int count = 0;
#         // Traverse all starting points
#         for (int i = 0; i < A.size(); i++) {
#             // Maintain xor of current subarray
#             int xorVal = 0;
#             // Extend subarray till end
#             for (int j = i; j < A.size(); j++) {
#                 // Update xor
#                 xorVal ^= A[j];
#                 // If xor equals B, increment count
#                 if (xorVal == B) {
#                     count++;
#                 }
#             }
#         }
#         return count;
#     }
# };
# int countSubarraysXOR(vector<int>& A, int B) {
#   unordered_map<int, int> freq;
#   int count = 0, xorSum = 0;
# 
#   for (int i = 0; i < A.size(); i++) {
#       xorSum ^= A[i];
# 
#       if (xorSum == B)
#           count++;
# 
#       if (freq.find(xorSum ^ B) != freq.end())
#           count += freq[xorSum ^ B];
# 
#       freq[xorSum]++;
#   }
# 
#   return count;
# }
# 
# int main()
# {
#     vector<int> a = {4, 2, 2, 6, 4};
#     int k = 6;
#     int ans = countSubarraysXOR(a, k);
#     cout << "The number of subarrays with XOR k is: "
#          << ans << "\n";
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
