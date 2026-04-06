# 440. K-th Smallest in Lexicographical Order.py - Python skeleton converted from C++

# Original C++ code:
# // Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
# 
#  
# 
# // Example 1:
# 
# // Input: n = 13, k = 2
# // Output: 10
# // Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
# 
# // Example 2:
# 
# // Input: n = 1, k = 1
# // Output: 1
# 
#  
# 
# // Constraints:
# 
# //     1 <= k <= n <= 109
# 
# #include<iostream>
# #include<vector>
# using namespace std;
# class Solution {
#   public:
#       // Count numbers between prefix and prefix + 1, limited by n
#       long long countSteps(long long n, long long prefix, long long nextPrefix) {
#           long long steps = 0;
#           while (prefix <= n) {
#               steps += std::min(n + 1, nextPrefix) - prefix;
#               prefix *= 10;
#               nextPrefix *= 10;
#           }
#           return steps;
#       }
#       
#       int findKthNumber(int n, int k) {
#           long long prefix = 1;
#           k = k - 1;  // because prefix = 1 is the first number
#   
#           while (k > 0) {
#               long long steps = countSteps(n, prefix, prefix + 1);
#               if (steps <= k) {
#                   // Move to next prefix (next sibling in the trie)
#                   prefix += 1;
#                   k -= steps;
#               } else {
#                   // Move to next level (child in the trie)
#                   prefix *= 10;
#                   k -= 1;
#               }
#           }
#           return (int)prefix;
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
