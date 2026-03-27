// C++ Program to find kth largest element
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Time Complexity: O(n), where n is the number of nodes in Binary tree.
// Auxiliary Space: O(1)
// Function to perform Morris Traversal and 
// return kth largest element
int kthLargest(Node* root, int k) {

    // return -1 if root is null
    if (root == nullptr) return -1;
    
    Node* curr = root;
    int cnt = 0;
    
    while (curr != nullptr) {
        
        // if right tree does not exists,
        // then increment the count, check 
        // count==k. Otherwise, 
        // set curr = curr->left
        if (curr->right == nullptr) {
            cnt++;
            
            // return current Node
            // if cnt == k.
            if (cnt == k) 
                return curr->data;
                
            curr = curr->left;    
        }
        else {
            Node* succ = curr->right;
            
            // find the inorder successor
            while (succ->left != nullptr && 
                   succ->left != curr) {
                succ = succ->left;
            }
            
            // create a linkage between succ and
            // curr 
            if (succ->left == nullptr) {
                succ->left = curr;
                curr = curr->right;
            }
            
            // if succ->left = curr, it means 
            // we have processed the right subtree,
            // and we can process curr node
            else {
                cnt++;  
                
                // remove the link 
                succ->left = nullptr;
                
                // return current Node
                // if cnt == k.
                if (cnt == k) 
                    return curr->data;
                
                curr = curr->left;
            }
        }
    }
    
    return -1;
}

int main() {

    // Create a hard coded tree.
    //         20
    //       /   \
    //      8     22
    //    /  \  
    //   4   12  
    //      /  \
    //     10   14
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    
    int k = 3;
    
    cout << kthLargest(root, k) << endl;

    return 0;
}