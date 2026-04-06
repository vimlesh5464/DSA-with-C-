// Given an integer array nums where the elements are sorted in ascending order, convert it to a binary search tree.

 

// Example 1:

// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:

// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

 

// Constraints:

//     1 <= nums.length <= 104
//     -104 <= nums[i] <= 104
//     nums is sorted in a strictly increasing order.

 
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper to build BST recursively
    TreeNode* buildBST(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildBST(nums, start, mid - 1);
        root->right = buildBST(nums, mid + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};

// Helper function: Inorder traversal to verify BST
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode* root = sol.sortedArrayToBST(nums);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
