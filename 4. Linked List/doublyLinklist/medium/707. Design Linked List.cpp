#include <iostream>
using namespace std;

//Version 1 — Simple Implementation (Only Head Pointer)
class MyLinkedList1 {
  public:
      struct Node {
          int val;
          Node* next;
          Node(int val) : val(val), next(nullptr) {}
      };
  
      Node* head;
      int size;
  
      MyLinkedList1() {
          head = nullptr;
          size = 0;
      }
  
      int get(int index) {
          if (index < 0 || index >= size) return -1;
          Node* curr = head;
          for (int i = 0; i < index; i++) {
              curr = curr->next;
          }
          return curr->val;
      }
  
      void addAtHead(int val) {
          Node* newNode = new Node(val);
          newNode->next = head;
          head = newNode;
          size++;
      }
  
      void addAtTail(int val) {
          Node* newNode = new Node(val);
          if (!head) {
              head = newNode;
          } else {
              Node* curr = head;
              while (curr->next) {
                  curr = curr->next;
              }
              curr->next = newNode;
          }
          size++;
      }
  
      void addAtIndex(int index, int val) {
          if (index < 0 || index > size) return;
  
          if (index == 0) {
              addAtHead(val);
              return;
          }
  
          Node* curr = head;
          for (int i = 0; i < index - 1; i++) {
              curr = curr->next;
          }
  
          Node* newNode = new Node(val);
          newNode->next = curr->next;
          curr->next = newNode;
          size++;
      }
  
      void deleteAtIndex(int index) {
          if (index < 0 || index >= size) return;
  
          Node* curr = head;
  
          if (index == 0) {
              head = head->next;
              delete curr;
          } else {
              for (int i = 0; i < index - 1; i++) {
                  curr = curr->next;
              }
              Node* temp = curr->next;
              curr->next = curr->next->next;
              delete temp;
          }
  
          size--;
      }
      // 🟢 Print function to display the linked list
    void printList() {
      Node* curr = head;
      cout << "Linked List: ";
      while (curr) {
          cout << curr->val << " ";
          curr = curr->next;
      }
      cout << endl;
  }
  };
  
  //Version 2 — Optimized Implementation (With Tail Pointer)

//This version makes addAtTail() O(1) instead of O(n).
class MyLinkedList {
  public:
      struct Node {
          int val;
          Node* next;
          Node(int val) : val(val), next(nullptr) {}
      };
  
      Node* head;
      Node* tail;
      int size;
  
      MyLinkedList() {
          head = nullptr;
          tail = nullptr;
          size = 0;
      }
  
      int get(int index) {
          if (index < 0 || index >= size) return -1;
          Node* curr = head;
          for (int i = 0; i < index; i++) {
              curr = curr->next;
          }
          return curr->val;
      }
  
      void addAtHead(int val) {
          Node* newNode = new Node(val);
          if (!head) {
              head = tail = newNode;
          } else {
              newNode->next = head;
              head = newNode;
          }
          size++;
      }
  
      void addAtTail(int val) {
          Node* newNode = new Node(val);
          if (!tail) {
              head = tail = newNode;
          } else {
              tail->next = newNode;
              tail = newNode;
          }
          size++;
      }
  
      void addAtIndex(int index, int val) {
          if (index < 0 || index > size) return;
          if (index == 0) return addAtHead(val);
          if (index == size) return addAtTail(val);
  
          Node* curr = head;
          for (int i = 0; i < index - 1; i++) {
              curr = curr->next;
          }
  
          Node* newNode = new Node(val);
          newNode->next = curr->next;
          curr->next = newNode;
          size++;
      }
  
      void deleteAtIndex(int index) {
          if (index < 0 || index >= size) return;
  
          Node* curr = head;
  
          if (index == 0) {
              head = head->next;
              delete curr;
              if (size == 1) tail = nullptr; // handle tail update
          } else {
              for (int i = 0; i < index - 1; i++) {
                  curr = curr->next;
              }
              Node* temp = curr->next;
              curr->next = curr->next->next;
              if (index == size - 1) tail = curr; // update tail
              delete temp;
          }
  
          size--;
      }
      // 🟢 Print function to display the linked list
    void printList() {
      Node* curr = head;
      cout << "Linked List: ";
      while (curr) {
          cout << curr->val << " ";
          curr = curr->next;
      }
      cout << endl;
  }
  };
  int main() {
    MyLinkedList linkedList;

    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2);  // 1 -> 2 -> 3
    cout << "After adding nodes: ";
    linkedList.printList();

    cout << "Get index 1: " << linkedList.get(1) << endl;  // Output: 2

    linkedList.deleteAtIndex(1);  // 1 -> 3
    cout << "After deleting index 1: ";
    linkedList.printList();

    linkedList.addAtHead(5);      // 5 -> 1 -> 3
    linkedList.addAtTail(7);      // 5 -> 1 -> 3 -> 7
    cout << "Final Linked List: ";
    linkedList.printList();

    return 0;
}
  