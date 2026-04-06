# 101-Check if two trees are Mirror.py - Python skeleton converted from C++

# Original C++ code:
# #include <iostream>
# #include <vector>
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
# int idx;
# 
# // Build tree using preorder
# Node* buildTree(vector<int>& nodes) {
#     idx++;
# 
#     if (idx >= nodes.size() || nodes[idx] == -1)
#         return nullptr;
# 
#     Node* newNode = new Node(nodes[idx]);
#     newNode->left = buildTree(nodes);
#     newNode->right = buildTree(nodes);
# 
#     return newNode;
# }
# 
# // Mirror check
# bool mirror(Node* t1, Node* t2) {
#     if (t1 == nullptr && t2 == nullptr)
#         return true;
# 
#     if (t1 == nullptr || t2 == nullptr)
#         return false;
# 
#     return (t1->data == t2->data) &&
#            mirror(t1->left, t2->right) &&
#            mirror(t1->right, t2->left);
# }
# 
# int main() {
# 
#     int n1;
#     cin >> n1;
# 
#     vector<int> tree1(n1);
#     for(int i = 0; i < n1; i++)
#         cin >> tree1[i];
# 
#     idx = -1;
#     Node* root1 = buildTree(tree1);
# 
#     int n2;
#     cin >> n2;
# 
#     vector<int> tree2(n2);
#     for(int i = 0; i < n2; i++)
#         cin >> tree2[i];
# 
#     idx = -1;
#     Node* root2 = buildTree(tree2);
# 
#     if (mirror(root1, root2))
#         cout << "Mirror Trees\n";
#     else
#         cout << "Not Mirror Trees\n";
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
