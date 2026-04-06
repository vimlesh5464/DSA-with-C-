# 102 Level_order_traversal.py - Python skeleton converted from C++

# Original C++ code:
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
# 
# // ---------------- Level Order Traversal ----------------
# vector<vector<int>> levelOrder(TreeNode* root) {
#     vector<vector<int>> result;
#     if (!root) return result;
# 
#     queue<TreeNode*> q;
#     q.push(root);
# 
#     while (!q.empty()) {
#         int size = q.size();
#         vector<int> level;
# 
#         for (int i = 0; i < size; i++) {
#             TreeNode* curr = q.front();
#             q.pop();
# 
#             level.push_back(curr->val);
# 
#             if (curr->left) q.push(curr->left);
#             if (curr->right) q.push(curr->right);
#         }
# 
#         result.push_back(level);
#     }
# 
#     return result;
# }
# 
# // ---------------- Recursive Build from Vector (Preorder) ----------------
# int idx = -1;  // global index for recursive build
# TreeNode* buildTree(vector<int>& nodes) {
#     idx++;
#     if (idx >= nodes.size() || nodes[idx] == -1) return nullptr;
# 
#     TreeNode* currNode = new TreeNode(nodes[idx]);
#     currNode->left = buildTree(nodes);
#     currNode->right = buildTree(nodes);
#     return currNode;
# }
# 
# // ---------------- Inorder Print ----------------
# void printInorder(TreeNode* root) {
#     if (!root) return;
#     printInorder(root->left);
#     cout << root->val << " ";
#     printInorder(root->right);
# }
# 
# // ---------------- Main ----------------
# int main() {
#     int n;
#     cout << "Enter number of nodes in preorder (-1 for NULL): ";
#     cin >> n;
# 
#     vector<int> nodes(n);
#     cout << "Enter nodes (-1 for NULL): ";
#     for (int i = 0; i < n; i++) cin >> nodes[i];
# 
#     idx = -1;  // reset before building
#     TreeNode* root = buildTree(nodes); // build tree from vector
# 
#     cout << "\nLevel Order Traversal:\n";
#     vector<vector<int>> ans = levelOrder(root);
#     for (auto &level : ans) {
#         for (int val : level) cout << val << " ";
#         cout << endl;
#     }
# 
#     cout << "\nInorder Traversal:\n";
#     printInorder(root);
#     cout << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
