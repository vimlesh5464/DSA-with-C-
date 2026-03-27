

// C++ program to check if a tree is BST
// Using specified range of Min and Max Values

#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

//[Approach - 1] Using specified range of Min and Max Values - O(n) Time and O(h) Space
// Time Complexity: O(n), where n is the number of nodes, as each node is visited once.
// Auxiliary Space: O(h), where h is the height of the tree, due to recursive calls (worst case O(n) for a skewed tree, O(log n) for a balanced tree).


// Helper function to check if a tree is BST within a given range
bool isBSTUtil(Node* node, int min, int max) {
    if (node == nullptr) 
      	return true;

    // If the current node's data 
    // is not in the valid range, return false
    if (node->data < min || node->data > max) 
      	return false;

    // Recursively check the left and 
    // right subtrees with updated ranges
    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}

// Function to check if the entire binary tree is a BST
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

//[Approach - 2] Using Inorder Traversal - O(n) Time and O(h) Space
// Time Complexity: O(n), where n is the number of nodes, as each node is visited once in inorder traversal.
// Auxiliary Space: O(h), where h is the height of the tree, due to recursive calls (worst case O(n) for a skewed tree, O(log n) for a balanced tree).
// Recursive Function for inorder traversal
bool inorder(Node* root, int &prev) {
  if (!root) 
      return true;

  // Recursively check the left subtree
  if (!inorder(root->left, prev)) 
      return false;

  // Check the current node value against the previous value
  if (prev >= root->data) 
      return false;
  
  // Update the previous value to the current node's value
  prev = root->data;

  // Recursively check the right subtree
  return inorder(root->right, prev);
}

// Function to check if the tree is a valid BST
bool isBST(Node* root) {
  int prev = INT_MIN;
  return inorder(root, prev);
}

//[Approach - 3] Using Morris Traversal - O(n) Time and O(1) Space


// Function to check if the binary tree is a BST using Morris Traversal
bool isBST(Node* root) {
  Node* curr = root;
  Node* pre = nullptr;
  int prevValue = INT_MIN; 

  while (curr != nullptr) {
      if (curr->left == nullptr) {
          
          // Process curr node
          if (curr->data <= prevValue) {
              
              // Not in ascending order
              return false; 
          }
          prevValue = curr->data;
          curr = curr->right;
      } else {
          
          // Find the inorder predecessor of curr
          pre = curr->left;
          while (pre->right != nullptr && pre->right != curr) {
              pre = pre->right;
          }

          if (pre->right == nullptr) {
              
              // Create a temporary thread to the curr node
              pre->right = curr;
              curr = curr->left;
          } else {
              
              // Remove the temporary thread
              pre->right = nullptr;

              // Process the curr node
              if (curr->data <= prevValue) {
                  
                  // Not in ascending order
                  return false; 
              }
              prevValue = curr->data;
              curr = curr->right;
          }
      }
  }

  return true; 
}


int main() {
  
    // Create a sample binary tree
    //     10
    //    /  \
    //   5    20
    //        / \
    //       9   25

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if (isBST(root))
        cout << "True" << endl;
    else 
        cout << "False" << endl;

    return 0;
}
