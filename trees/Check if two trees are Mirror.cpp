#include <iostream>
#include <vector>
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

bool mirror(Node* nodes1, Node* nodes2) {
    if (nodes1 == nullptr && nodes2 == nullptr) {
        return true;
    }
    if (nodes1 == nullptr || nodes2 == nullptr) {
        return false; // ❌ previously you returned true
    }

    return (nodes1->data == nodes2->data) &&
           mirror(nodes1->left, nodes2->right) && // ❌ left vs right
           mirror(nodes1->right, nodes2->left);   // ❌ right vs left
}

int main() {
    // Example trees
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node* root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->right->left = new Node(5);
    root2->right->right = new Node(4);

    if (mirror(root1, root2)) {
        cout << "The trees are mirrors of each other!" << endl;
    } else {
        cout << "The trees are NOT mirrors of each other!" << endl;
    }

    return 0;
}
