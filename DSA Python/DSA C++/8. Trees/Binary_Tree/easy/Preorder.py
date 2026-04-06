# Preorder.py - Python skeleton converted from C++

# Original C++ code:
# #include <iostream>
# using namespace std;
# 
# struct Node {
#   public:
#     int data;
#     Node* left;
#     Node* right;
#     
#     Node(int data) {
#         this->data = data;
#         left = right = NULL;
#     }
# };
# 
# void preorder(Node* root) {
#     if (root == NULL) {
#         return;
#     }
#     cout << root->data << endl;
#     preorder(root->left);
#     preorder(root->right);
# }
# 
# int main() {
#     Node* root = new Node(1);
#     root->left = new Node(2);
#     root->right = new Node(3);
#     root->left->left = new Node(4);
#     root->left->right = new Node(5);
# 
#     preorder(root);
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
