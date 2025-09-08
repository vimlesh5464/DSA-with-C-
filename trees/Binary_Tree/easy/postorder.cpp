#include <iostream>
using namespace std;

struct Node {
  public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout << root->data << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    preorder(root);
}