#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

// 🔥 Correct BST insertion
Node* insertBST(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// Traversals
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {

    Node* root = nullptr;
    int k;

    while (true) {
        cin >> k;

        switch (k) {

            case 1: {
                int n;
                cin >> n;

                for (int i = 0; i < n; i++) {
                    int val;
                    cin >> val;
                    root = insertBST(root, val);
                }
                break;
            }

            case 2:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;

            case 5:
                return 0;
        }
    }
}