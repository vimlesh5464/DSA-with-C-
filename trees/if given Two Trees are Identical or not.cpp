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
// ✅ Check if two trees are identical
bool identical(Node* nodes1, Node* nodes2) {
  if (nodes1 == nullptr && nodes2 == nullptr) {
      return true;
  }
  if (nodes1 == nullptr || nodes2 == nullptr) {
      return false;
  }

  return (nodes1->data == nodes2->data) &&
         identical(nodes1->left, nodes2->left) &&
         identical(nodes1->right, nodes2->right);
}


int main() {
    // Example trees
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->right->right = new Node(5);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->right->right = new Node(5);

    if (identical(root1, root2)) {
        cout << "The trees are identical of each other!" << endl;
    } else {
        cout << "The trees are NOT identical of each other!" << endl;
    }

    return 0;
}
