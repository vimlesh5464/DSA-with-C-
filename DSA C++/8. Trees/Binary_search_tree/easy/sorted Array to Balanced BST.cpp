
// C++ program to convert sorted 
// array to BST.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
  
class Node { 
public:
    int data; 
    Node* left; 
    Node* right; 
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
//[Expected Approach - 1] Using Recursion - O(n) Time and O(n) Space
// Time Complexity: O(n), where n is the number of elements in the input array.
// Auxiliary Space: O(n), because we create one node for each element in the input array.
// Recursive function to construct BST
Node* sortedArrayToBSTRecur(vector<int>& arr, 
                               int start, int end) {
    if(start > end) return nullptr;
    
    // Find the middle element
    int mid = start + (end - start) / 2;
    
    // Create root node
    Node* root = new Node(arr[mid]);
    
    // Create left subtree
    root->left = sortedArrayToBSTRecur(arr, start, 
                                      mid - 1);
                                      
    // Create right subtree
    root->right = sortedArrayToBSTRecur(arr, mid + 1,
                                       end);
    return root;
}

Node* sortedArrayToBST(vector<int> &arr) {
    int n = arr.size();
    return sortedArrayToBSTRecur(arr, 0, n-1);
}


//[Expected Approach - 2] Using queue - O(n) Time and O(n) Space

// Step-by-step approach:

//     First initialize a queue with root node (which the mid of initial array) and two variables.
//     Lets say start and end which will describe the range of the root (set to 0 and n-1 for root node).
//      Loop until the queue is empty.

//     Remove first node from the queue along with its start and end range and find middle index of the 
//     range. Elements present in the range [start, middle-1] will be present in its left subtree and 
//     elements in the range [middle+1, end] will be present in the right subtree.

//     If left subtree exists, that is, if start is less than middle index. Then create the left node 
//     with the value equal to middle of range [start, middle-1]. Link the root node and left node and 
//     push the left node along withrange into the queue.

//     If right subtree exists, that is, if end is greater than middle index. Then create the right node 
//     with the value equal to middle of range [middle+1, end]. Link the root node and right node and 
//     push the right node along range into the queue.

//     Return the root node.

Node *sortedArrayToBST(vector<int> &arr) {
  int n = arr.size();

  if (n == 0)
      return nullptr;

  // create the root node.
  int mid = (n - 1) / 2;
  Node *root = new Node(arr[mid]);

  queue<pair<Node *, pair<int, int>>> q;
  q.push({root, {0, n - 1}});

  while (!q.empty()) {
      pair<Node *, pair<int, int>> front = q.front();
      q.pop();

      Node *curr = front.first;
      int s = front.second.first, e = front.second.second;
      int index = s + (e - s) / 2;

      // if left subtree exists
      if (s < index) {
          int mid = s + (index - 1 - s) / 2;
          Node *left = new Node(arr[mid]);
          curr->left = left;
          q.push({left, {s, index - 1}});
      }

      // if right subtree exists
      if (e > index) {
          int mid = index + 1 + (e - index - 1) / 2;
          Node *right = new Node(arr[mid]);
          curr->right = right;
          q.push({right, {index + 1, e}});
      }
  }

  return root;
}

void preOrder(Node* root) {
  if(root == nullptr) return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}


int main(){
    
    vector<int> arr = {1, 2, 3, 4};
    Node* root = sortedArrayToBST(arr);
    preOrder(root);
    
    return 0;
}