#include <iostream>
#include <vector>
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

// 1. Vector-Based Approach
// Merge using vector
Node* mergeTwoLinklistVector(Node* list1, Node* list2) {
    vector<int> ans;
    Node* i = list1;
    Node* j = list2;

    while (i != nullptr && j != nullptr) {
        if (i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while (i != nullptr) {
        ans.push_back(i->data);
        i = i->next;
    }

    while (j != nullptr) {
        ans.push_back(j->data);
        j = j->next;
    }

    // Build new linked list
    Node* head = new Node(ans[0]);
    Node* curr = head;
    for (int k = 1; k < ans.size(); k++) {
        curr->next = new Node(ans[k]);
        curr = curr->next;
    }
    return head;
}
//2. Pointer-Based Approach (Efficient)
// Merge using pointers
Node* mergeTwoLinklist(Node* list1, Node* list2) {
  Node dummy(-1);  // dummy node
  Node* tail = &dummy;

  while (list1 != NULL && list2 != NULL) {
      if (list1->data <= list2->data) {
          tail->next = list1;
          list1 = list1->next;
      } else {
          tail->next = list2;
          list2 = list2->next;
      }
      tail = tail->next;
  }

  if (list1 != NULL) tail->next = list1;
  if (list2 != NULL) tail->next = list2;

  return dummy.next;
}

// Driver code
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    insert(list1, 1);
    insert(list1, 3);
    insert(list1, 5);

    insert(list2, 2);
    insert(list2, 4);
    insert(list2, 6);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    Node* merged = mergeTwoLinklistVector(list1, list2);

    cout << "Merged List (Vector): ";
    printList(merged);

    return 0;
}
