#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Time Complexity → O(n), each node is pushed and popped at most once.

// Space Complexity → O(n) for the stack in the worst case (completely skewed tree).
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);

        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);

            // Case 1: New value < top → left child
            if (preorder[i] < st.top()->val) {
                st.top()->left = node;
            } 
            // Case 2: New value > top → find parent for right child
            else {
                TreeNode* parent = nullptr;
                while (!st.empty() && preorder[i] > st.top()->val) {
                    parent = st.top();
                    st.pop();
                }
                parent->right = node;
            }

            st.push(node);
        }

        return root;
    }
};

// Helper: Inorder traversal to verify BST
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder Traversal of BST: ";
    inorder(root);  // should print sorted values
    cout << endl;

    return 0;
}
