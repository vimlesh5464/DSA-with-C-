# 707. Design Linked List.py - Python skeleton converted from C++

# Original C++ code:
# // Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
# // A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
# // If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.
# 
# // Implement the MyLinkedList class:
# 
# //     MyLinkedList() Initializes the MyLinkedList object.
# //     int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
# //     void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
# //     void addAtTail(int val) Append a node of value val as the last element of the linked list.
# //     void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
# //     void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
# 
#  
# 
# // Example 1:
# 
# // Input
# // ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
# // [[], [1], [3], [1, 2], [1], [1], [1]]
# // Output
# // [null, null, null, null, 2, null, 3]
# 
# // Explanation
# // MyLinkedList myLinkedList = new MyLinkedList();
# // myLinkedList.addAtHead(1);
# // myLinkedList.addAtTail(3);
# // myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
# // myLinkedList.get(1);              // return 2
# // myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
# // myLinkedList.get(1);              // return 3
# 
#  
# 
# // Constraints:
# 
# //     0 <= index, val <= 1000
# //     Please do not use the built-in LinkedList library.
# //     At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.
# 
#  
# 
# #include <iostream>
# using namespace std;
# 
# //Version 1 — Simple Implementation (Only Head Pointer)
# class MyLinkedList1 {
#   public:
#       struct Node {
#           int val;
#           Node* next;
#           Node(int val) : val(val), next(nullptr) {}
#       };
#   
#       Node* head;
#       int size;
#   
#       MyLinkedList1() {
#           head = nullptr;
#           size = 0;
#       }
#   
#       int get(int index) {
#           if (index < 0 || index >= size) return -1;
#           Node* curr = head;
#           for (int i = 0; i < index; i++) {
#               curr = curr->next;
#           }
#           return curr->val;
#       }
#   
#       void addAtHead(int val) {
#           Node* newNode = new Node(val);
#           newNode->next = head;
#           head = newNode;
#           size++;
#       }
#   
#       void addAtTail(int val) {
#           Node* newNode = new Node(val);
#           if (!head) {
#               head = newNode;
#           } else {
#               Node* curr = head;
#               while (curr->next) {
#                   curr = curr->next;
#               }
#               curr->next = newNode;
#           }
#           size++;
#       }
#   
#       void addAtIndex(int index, int val) {
#           if (index < 0 || index > size) return;
#   
#           if (index == 0) {
#               addAtHead(val);
#               return;
#           }
#   
#           Node* curr = head;
#           for (int i = 0; i < index - 1; i++) {
#               curr = curr->next;
#           }
#   
#           Node* newNode = new Node(val);
#           newNode->next = curr->next;
#           curr->next = newNode;
#           size++;
#       }
#   
#       void deleteAtIndex(int index) {
#           if (index < 0 || index >= size) return;
#   
#           Node* curr = head;
#   
#           if (index == 0) {
#               head = head->next;
#               delete curr;
#           } else {
#               for (int i = 0; i < index - 1; i++) {
#                   curr = curr->next;
#               }
#               Node* temp = curr->next;
#               curr->next = curr->next->next;
#               delete temp;
#           }
#   
#           size--;
#       }
#       // 🟢 Print function to display the linked list
#     void printList() {
#       Node* curr = head;
#       cout << "Linked List: ";
#       while (curr) {
#           cout << curr->val << " ";
#           curr = curr->next;
#       }
#       cout << endl;
#   }
#   };
#   
#   //Version 2 — Optimized Implementation (With Tail Pointer)
# 
# //This version makes addAtTail() O(1) instead of O(n).
# class MyLinkedList {
#   public:
#       struct Node {
#           int val;
#           Node* next;
#           Node(int val) : val(val), next(nullptr) {}
#       };
#   
#       Node* head;
#       Node* tail;
#       int size;
#   
#       MyLinkedList() {
#           head = nullptr;
#           tail = nullptr;
#           size = 0;
#       }
#   
#       int get(int index) {
#           if (index < 0 || index >= size) return -1;
#           Node* curr = head;
#           for (int i = 0; i < index; i++) {
#               curr = curr->next;
#           }
#           return curr->val;
#       }
#   
#       void addAtHead(int val) {
#           Node* newNode = new Node(val);
#           if (!head) {
#               head = tail = newNode;
#           } else {
#               newNode->next = head;
#               head = newNode;
#           }
#           size++;
#       }
#   
#       void addAtTail(int val) {
#           Node* newNode = new Node(val);
#           if (!tail) {
#               head = tail = newNode;
#           } else {
#               tail->next = newNode;
#               tail = newNode;
#           }
#           size++;
#       }
#   
#       void addAtIndex(int index, int val) {
#           if (index < 0 || index > size) return;
#           if (index == 0) return addAtHead(val);
#           if (index == size) return addAtTail(val);
#   
#           Node* curr = head;
#           for (int i = 0; i < index - 1; i++) {
#               curr = curr->next;
#           }
#   
#           Node* newNode = new Node(val);
#           newNode->next = curr->next;
#           curr->next = newNode;
#           size++;
#       }
#   
#       void deleteAtIndex(int index) {
#           if (index < 0 || index >= size) return;
#   
#           Node* curr = head;
#   
#           if (index == 0) {
#               head = head->next;
#               delete curr;
#               if (size == 1) tail = nullptr; // handle tail update
#           } else {
#               for (int i = 0; i < index - 1; i++) {
#                   curr = curr->next;
#               }
#               Node* temp = curr->next;
#               curr->next = curr->next->next;
#               if (index == size - 1) tail = curr; // update tail
#               delete temp;
#           }
#   
#           size--;
#       }
#       // 🟢 Print function to display the linked list
#     void printList() {
#       Node* curr = head;
#       cout << "Linked List: ";
#       while (curr) {
#           cout << curr->val << " ";
#           curr = curr->next;
#       }
#       cout << endl;
#   }
#   };
#   int main() {
#     MyLinkedList linkedList;
# 
#     linkedList.addAtHead(1);
#     linkedList.addAtTail(3);
#     linkedList.addAtIndex(1, 2);  // 1 -> 2 -> 3
#     cout << "After adding nodes: ";
#     linkedList.printList();
# 
#     cout << "Get index 1: " << linkedList.get(1) << endl;  // Output: 2
# 
#     linkedList.deleteAtIndex(1);  // 1 -> 3
#     cout << "After deleting index 1: ";
#     linkedList.printList();
# 
#     linkedList.addAtHead(5);      // 5 -> 1 -> 3
#     linkedList.addAtTail(7);      // 5 -> 1 -> 3 -> 7
#     cout << "Final Linked List: ";
#     linkedList.printList();
# 
#     return 0;
# }
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
