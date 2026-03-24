// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

//     LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
//     int get(int key) Return the value of the key if the key exists, otherwise return -1.
//     void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

// The functions get and put must each run in O(1) average time complexity.

 

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

 

// Constraints:

//     1 <= capacity <= 3000
//     0 <= key <= 104
//     0 <= value <= 105
//     At most 2 * 105 calls will be made to get and put.

#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LRUCache {
  public:
  class Node {
      public:
          int key;
          int val;
          Node* next;
          Node* prev;
          // Constructor to initialize node
          Node(int _key, int _val) {
              key = _key;
              val = _val;
          }
      };
  
      // Head and tail dummy nodes
      Node* head = new Node(-1, -1);
      Node* tail = new Node(-1, -1);
  
  // Capacity of cache
      int cap;
      // Hash map to store key-node mapping
      unordered_map<int, Node*> m;
      LRUCache(int capacity) {
           cap = capacity;
          head->next = tail;
          tail->prev = head;
      }
      // Function to add a node right after head
      void addNode(Node* newNode) {
          Node* temp = head->next;
          newNode->next = temp;
          newNode->prev = head;
          head->next = newNode;
          temp->prev = newNode;
      }
  
      // Function to remove a given node from list
      void deleteNode(Node* delNode) {
          Node* delPrev = delNode->prev;
          Node* delNext = delNode->next;
          delPrev->next = delNext;
          delNext->prev = delPrev;
      }
      
      int get(int key) {
          // If key exists in cache
          if (m.find(key) != m.end()) {
              Node* resNode = m[key];
              int res = resNode->val;
              // Remove old mapping
              m.erase(key);
              // Move accessed node to front
              deleteNode(resNode);
              addNode(resNode);
              // Update map
              m[key] = head->next;
              return res;
          }
          // If not found
          return -1;
      }
      
      void put(int key, int value) {
          // If key already exists
          if (m.find(key) != m.end()) {
              Node* existingNode = m[key];
              m.erase(key);
              deleteNode(existingNode);
          }
          // If capacity reached
          if (m.size() == cap) {
              m.erase(tail->prev->key);
              deleteNode(tail->prev);
          }
          // Insert new node at front
          addNode(new Node(key, value));
          m[key] = head->next;
      }
  };
  