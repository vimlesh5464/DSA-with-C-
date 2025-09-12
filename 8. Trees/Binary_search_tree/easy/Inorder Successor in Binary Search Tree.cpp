// Approach:

//     We follow the idea of normal BST Search. In BST search, we get closer to the key by comparing with the current node. So the last greater key visited during search is the successor. The following cases arise during the search.

//         If we reach null, then the given target does not exist, we return null
//         If current node matches the target and right child is not empty, then successor is leftmost node in right subtree.
//         If current node is greater , then it is a potential successor, we mark it as successor and proceed to left
//         If current node is smaller or equal to the target, we proceed to right.

// C++ Program to find Inorder Successor in 
// Binary Search Tree

// Time Complexity: O(h), where h is the height of the tree. 
// Auxiliary Space: O(1)


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* leftMost(Node* node) {
    Node* curr = node;
    while (curr->left != nullptr) 
        curr = curr->left;
    return curr;
}


Node* getSucc(Node* root, int target) {
    
    // Base Case 1: No Inorder Successor
    if (root == nullptr)
        return nullptr;
     
    // Base Case 2: root is same as target and 
    // right child is not empty
    if (root->data == target && root->right != nullptr)
        return leftMost(root->right);

    // Use BST properties to search for 
    // target and successor
    Node* succ = nullptr;
    Node* curr = root; 
    while (curr != nullptr) {
      
        // If curr node is greater, then it
        // is a potential successor
        if (target < curr->data) {
            succ = curr;
            curr = curr->left;
        }
      
        // If smaller, then successor must
        // be in the right child
        else if (target >= curr->data) 
            curr = curr->right;
      
    }

    return succ;
}

int main() {
  
    // Construct a BST
    //            20
    //          /    \
    //         8      22
    //       /   \
    //      4    12
    //          /  \
    //         10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
  
    int target = 14;
    Node* succ = getSucc(root, target);
    if (succ != nullptr)
        cout << succ->data;
    else
        cout << "null";
    return 0;
}