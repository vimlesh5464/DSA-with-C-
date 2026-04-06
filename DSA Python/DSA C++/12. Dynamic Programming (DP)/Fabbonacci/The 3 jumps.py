# The 3 jumps.py - Python skeleton converted from C++

# Original C++ code:
# // You need to find the minimum cost to reach the last element of a 
# // given vector V of positive integers of size N.
# 
# // The cost of moving from one element to another is 
# // the absolute difference between the elements.
# 
# // You can only take a jump of max size equal to 3, i.e. 
# // if you are at index i, you can go to i+1,i+2 or i+3.
# 
#  
# 
# // Note : the cost of reaching to the first element is 0.
# 
# // Input Format
# 
# // The first line is the size of the vector denoted by N
# 
# // The second line contains N space-separated integers representing the elements of the vector.
# 
# // Output Format
# 
# // Display the minimum cost to reach the end with given constraints.
# 
# // Constraints
# 
# // 1 ≤ V[i] ≤ 10^10
# 
# // 1 ≤ N ≤ 10^3
# 
# // Sample Testcase 0
# 
# // Testcase Input
# // 5
# // 30 10 60 10 60
# // Testcase Output
# // 30
# // Explanation
# 
# // If we start from 30, take a step to 60 which costs 30 and then 
# //take a step to 60 which costs 0. Therefore, the total cost, in this case, would be 30+0 = 30. 
# 
# 
# // This path has the minimum cost.
# // Sample Testcase 1
# 
# // Testcase Input
# // 6
# // 40 20 10 30 90 80
# // Testcase Output
# // 60
# // Explanation
# 
# // We start from 40, then take a step to 30 which costs 10, and 
# //then take a step to 80 which costs 50. 
# 
# 
# // Therefore, the total cost is 10+50= 60.
# #include <iostream>
# #include <vector>
# #include <cmath>
# #include <algorithm>
# using namespace std;
# 
# 
# long long solve(int i, vector<long long>& V) {
#     // Base case
#     if (i == 0) return 0;
# 
#     long long ans = 1e18;
# 
#     // Jump from i-1
#     ans = min(ans, solve(i - 1, V) + abs(V[i] - V[i - 1]));
# 
#     // Jump from i-2
#     if (i >= 2)
#         ans = min(ans, solve(i - 2, V) + abs(V[i] - V[i - 2]));
# 
#     // Jump from i-3
#     if (i >= 3)
#         ans = min(ans, solve(i - 3, V) + abs(V[i] - V[i - 3]));
# 
#     return ans;
# }
# 
# 
# 
# int main() {
#     int n;
#     cin >> n;
#     vector<long long> V(n);
#     for(int i = 0; i < n; i++) cin >> V[i];
# 
#     vector<long long> dp(n, 1e18); // Initialize with large number
#     dp[0] = 0; // Cost to reach first element
# 
#     for(int i = 1; i < n; i++){
#         // Jump from i-1
#         dp[i] = min(dp[i], dp[i-1] + abs(V[i] - V[i-1]));
#         // Jump from i-2
#         if(i >= 2) dp[i] = min(dp[i], dp[i-2] + abs(V[i] - V[i-2]));
#         // Jump from i-3
#         if(i >= 3) dp[i] = min(dp[i], dp[i-3] + abs(V[i] - V[i-3]));
#     }
# 
#     cout << dp[n-1] << endl;
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
