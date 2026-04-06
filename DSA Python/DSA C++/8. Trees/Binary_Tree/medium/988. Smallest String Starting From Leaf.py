# 988. Smallest String Starting From Leaf.py - Python skeleton converted from C++

# Original C++ code:
# 
# #include <iostream>
# #include <vector>
# #include <queue>
# using namespace std;
# 
# struct TreeNode {
#     int val;
#     TreeNode* left;
#     TreeNode* right;
#     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
# };
# class Solution {
#   public:
#       string smallestFromLeaf(TreeNode* root) {
#           string smallest = "~";          // lexicographically very large
#           vector<char> path;
#           dfs(root, path, smallest);
#           return smallest;
#       }
#   
#       void dfs(TreeNode* node, vector<char>& path, string &smallest) {
#           if (!node) return;
#   
#           // add current node char
#           path.push_back('a' + node->val);
#   
#           // if leaf node
#           if (!node->left && !node->right) {
#               string s(path.rbegin(), path.rend());  // leaf → root
#               if (s < smallest) smallest = s;
#           }
#   
#           // recurse
#           dfs(node->left, path, smallest);
#           dfs(node->right, path, smallest);
#   
#           // backtrack
#           path.pop_back();
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
