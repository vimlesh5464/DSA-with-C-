#include <iostream>
#include<unordered_set>
using namespace std;

// Linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert node at end
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Solution class
class Solution {
public:
    Node* getIntersectionNode(Node* headA, Node* headB) {
        if (!headA || !headB) return NULL;

        Node* a = headA;
        Node* b = headB;

        while (a != b) {
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        return a; // intersection node or NULL
    }
};

// Solution class
class Solution {
  public:
      Node* getIntersectionNode(Node* headA, Node* headB) {
          Node* temp = headA;
          while(headB!=NULL){
            while(temp!=NULL){
              if(temp==headB){
                return headB;
              }
              temp=temp->next;
            }
            headB=headB->next;
          }
          return NULL;
      }
  };
  
  class Solution {
    public:
        Node* getIntersectionNode(Node* headA, Node* headB) {
          unordered_set<Node*> st;
          while(headA != NULL) {
             st.insert(headA);
             headA = headA->next;
          }
          while(headB != NULL) {
              if(st.find(headB) != st.end()) return headB;
              headB = headB->next;
          }
          return NULL;
        }
    };
    
// Driver code
int main() {
    // Create two linked lists
    Node* headA = NULL;
    Node* headB = NULL;

    // List A: 4 -> 1 -> 8 -> 4 -> 5
    insert(headA, 4);
    insert(headA, 1);
    Node* inter = new Node(8);
    headA->next->next = inter;
    inter->next = new Node(4);
    inter->next->next = new Node(5);

    // List B: 5 -> 6 -> 1 -> (intersect at 8)
    insert(headB, 5);
    insert(headB, 6);
    insert(headB, 1);
    headB->next->next->next = inter; // intersection link

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    Solution sol;
    Node* result = sol.getIntersectionNode(headA, headB);

    if (result)
        cout << "Intersection Node: " << result->data << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}
