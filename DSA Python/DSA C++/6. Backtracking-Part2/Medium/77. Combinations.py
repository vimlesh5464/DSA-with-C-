# 77. Combinations.py - Python skeleton converted from C++

# Original C++ code:
# // Given two integers n and k, return all possible combinations of k 
# //numbers chosen from the range [1, n].
# 
# // You may return the answer in any order.
# 
#  
# 
# // Example 1:
# 
# // Input: n = 4, k = 2
# // Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
# // Explanation: There are 4 choose 2 = 6 total combinations.
# // Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
# 
# // Example 2:
# 
# // Input: n = 1, k = 1
# // Output: [[1]]
# // Explanation: There is 1 choose 1 = 1 total combination.
# 
#  
# 
# // Constraints:
# 
# //     1 <= n <= 20
# //     1 <= k <= n
# 
# #include<iostream>
# #include<vector>
# #include<map>
# using namespace std;
# void Combinations(int n, int k, int i, vector<vector<int>>&ans,vector<int>& subset){
#   if(k==0){
#     ans.push_back(subset);
#     return;
#   }
#   for(int index=i; index<=n; index++){
#     subset.push_back(index);
#     Combinations(n,k-1,index+1,ans,subset);
#     subset.pop_back();
#   }
# }
# int main(){
#   vector<vector<int>>ans;
#   vector<int>subset;
#   int n=4;
#   int k=2;
#   Combinations(n,k,1,ans,subset);
#   for(int i = 0; i < ans.size(); i++){
#     for(int j = 0; j < ans[i].size(); j++){
#       cout<<ans[i][j];
#     }
#     cout<<endl;
#   }
#   return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
