#include <iostream>
#include<vector>
using namespace std;
// Structure for Doubly Linked List Node
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node* head, int x) {
        vector<int> arr;
        vector<pair<int, int>> result;

        // Step 1: Store all node values in a vector
        Node* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        // Step 2: Two-pointer approach on vector
        int i = 0, j = arr.size() - 1;

        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == x) {
                result.push_back({arr[i], arr[j]});
                i++;
                j--;
            } else if (sum < x) {
                i++;
            } else {
                j--;
            }
        }

        return result;
    }
};


class Solution {
  public:
      vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
          vector<pair<int, int>> ans;
          Node* temp = head;
  
          // Traverse each pair of nodes
          while (temp != NULL) {
              Node* temp1 = temp->next;
              while (temp1 != NULL) {
                  if (temp->data + temp1->data == target) {
                      ans.push_back({temp->data, temp1->data});
                  }
                  temp1 = temp1->next;
              }
              temp = temp->next;
          }
  
          return ans;
      }
  };

  class Solution {
    public:
    Node* findTail(Node* head) {
            Node* tail = head;
            while (tail->next != NULL)
                tail = tail->next;
            return tail;
        }
        vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
           vector<pair<int, int>> ans;
    
            if (head == NULL) return ans;
    
            Node* left = head;
            Node* right = findTail(head);
            
            // Traverse each pair of nodes
            while (left != right && left->data < right->data) {
                int sum = left->data + right->data;
    
                if (sum == target) {
                    ans.push_back({left->data, right->data});
                    left = left->next;
                    right = right->prev;
                }
                else if (sum < target) {
                    left = left->next;
                }
                else {
                    right = right->prev;
                }
            }
            return ans;
        }
    };
    
  

// Helper function to add node at beginning
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}

int main() {
    Node* head = NULL;

    // Create sorted doubly linked list: 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
    push(&head, 9);
    push(&head, 8);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 2);
    push(&head, 1);

    int x = 7;
    Solution obj;
    vector<pair<int, int>> ans = obj.findPairsWithGivenSum(head, x);

    cout << "Pairs with sum " << x << " are:\n";
    for (auto &p : ans)
        cout << "(" << p.first << ", " << p.second << ") ";
    cout << endl;

    return 0;
}
