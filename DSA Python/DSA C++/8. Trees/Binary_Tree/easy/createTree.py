# createTree.py - Python skeleton converted from C++

# Original C++ code:
# #include<iostream>
# #include<vector>
# using namespace std;
# 
# class Node {
# public:
#     int data;
#     Node* left;
#     Node* right;
# 
#     Node(int data) {
#         this->data = data;
#         left = right = nullptr;
#     }
# };
# 
# static int idx = -1;
# 
# Node* buildTree(vector<int>& nodes) {
#     idx++;
# 
#     // safety check
#     if (idx >= nodes.size() || nodes[idx] == -1) {
#         return nullptr;
#     }
# 
#     Node* currNode = new Node(nodes[idx]);
#     currNode->left = buildTree(nodes);
#     currNode->right = buildTree(nodes);
# 
#     return currNode;
# }
# 
# void inorder(Node* root, vector<int>& result) {
#     if (root == nullptr) return;
# 
#     inorder(root->left, result);
#     result.push_back(root->data);
#     inorder(root->right, result);
# }
# 
# int main() {
#     int n;
#     cin >> n;
# 
#     vector<int> nodes(n);
#     for (int i = 0; i < n; i++) {
#         cin >> nodes[i];
#     }
# 
#     idx = -1;
#     Node* root = buildTree(nodes);
# 
#     vector<int> result;
#     inorder(root, result);
# 
#     for (int x : result) {
#         cout << x << " ";
#     }
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
