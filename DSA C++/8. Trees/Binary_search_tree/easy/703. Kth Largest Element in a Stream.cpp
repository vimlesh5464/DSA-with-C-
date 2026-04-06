// You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

// You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

// Implement the KthLargest class:

//     KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
//     int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.

 

// Example 1:

// Input:
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

// Output: [null, 4, 5, 5, 8, 8]

// Explanation:

// KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
// kthLargest.add(3); // return 4
// kthLargest.add(5); // return 5
// kthLargest.add(10); // return 5
// kthLargest.add(9); // return 8
// kthLargest.add(4); // return 8

// Example 2:

// Input:
// ["KthLargest", "add", "add", "add", "add"]
// [[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]

// Output: [null, 7, 7, 7, 8]

// Explanation:
// KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
// kthLargest.add(2); // return 7
// kthLargest.add(10); // return 7
// kthLargest.add(9); // return 7
// kthLargest.add(9); // return 8

 

// Constraints:

//     0 <= nums.length <= 104
//     1 <= k <= nums.length + 1
//     -104 <= nums[i] <= 104
//     -104 <= val <= 104
//     At most 104 calls will be made to add.

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