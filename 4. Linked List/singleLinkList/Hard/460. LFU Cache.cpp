// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the LFUCache class:

//     LFUCache(int capacity) Initializes the object with the capacity of the data structure.
//     int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
//     void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.

// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

// The functions get and put must each run in O(1) average time complexity.

 

// Example 1:

// Input
// ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, 3, null, -1, 3, 4]

// Explanation
// // cnt(x) = the use counter for key x
// // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
// LFUCache lfu = new LFUCache(2);
// lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
// lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
// lfu.get(1);      // return 1
//                  // cache=[1,2], cnt(2)=1, cnt(1)=2
// lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
//                  // cache=[3,1], cnt(3)=1, cnt(1)=2
// lfu.get(2);      // return -1 (not found)
// lfu.get(3);      // return 3
//                  // cache=[3,1], cnt(3)=2, cnt(1)=2
// lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
//                  // cache=[4,3], cnt(4)=1, cnt(3)=2
// lfu.get(1);      // return -1 (not found)
// lfu.get(3);      // return 3
//                  // cache=[3,4], cnt(4)=1, cnt(3)=3
// lfu.get(4);      // return 4
//                  // cache=[4,3], cnt(4)=2, cnt(3)=3

 

// Constraints:

//     1 <= capacity <= 104
//     0 <= key <= 105
//     0 <= value <= 109
//     At most 2 * 105 calls will be made to get and put.

#include <iostream>
#include<map>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Node {
  int key, value, cnt;
  Node *next; 
  Node *prev;
  Node(int _key, int _value) {
      key = _key;
      value = _value; 
      cnt = 1; 
  }
}; 

// To implement the doubly linked list
struct List {
  int size; // Size 
  Node *head; // Dummy head
  Node *tail; // Dummy tail
  
  // Constructor
  List() {
      head = new Node(0, 0); 
      tail = new Node(0,0); 
      head->next = tail;
      tail->prev = head; 
      size = 0;
  }
  
  // Function to add node in front 
  void addFront(Node *node) {
      Node* temp = head->next;
      node->next = temp;
      node->prev = head;
      head->next = node;
      temp->prev = node;
      size++; 
  }
  
  // Function to remove node from the list
  void removeNode(Node* delnode) {
      Node* prevNode = delnode->prev;
      Node* nextNode = delnode->next;
      prevNode->next = nextNode;
      nextNode->prev = prevNode;
      size--; 
  }
};
class LFUCache {

private:

  // Hashmap to store the key-nodes pairs
  map<int, Node*> keyNode; 
  
  /* Hashmap to maintain the lists 
  having different frequencies */
  map<int, List*> freqListMap; 
  
  int maxSizeCache; // Max size of cache
  
  /* To store the frequency of least 
  frequently used data-item */
  int minFreq; 
  
  // To store current size of cache
  int curSize; 
  public:
   LFUCache(int capacity) {
       // Set the capacity
      maxSizeCache = capacity; 
      minFreq = 0; // Set minimum frequency
      curSize = 0; // Set current frequency
   }
   // Method to update frequency of data-items
  void updateFreqListMap(Node *node) {
      
      // Remove from Hashmap
      keyNode.erase(node->key); 
      
      // Update the frequency list hashmap
      freqListMap[node->cnt]->removeNode(node); 
      
      // If node was the last node having it's frequency
      if(node->cnt == minFreq && 
         freqListMap[node->cnt]->size == 0) {
             
          // Update the minimum frequency
          minFreq++; 
      }
      
      // Creating a dummy list for next higher frequency
      List* nextHigherFreqList = new List();
      
      // If the next higher frequency list already exists
      if(freqListMap.find(node->cnt + 1) != 
         freqListMap.end()) {
             
          // Update pointer to already existing list
          nextHigherFreqList = freqListMap[node->cnt + 1];
      } 
      
      // Increment the count of data-item
      node->cnt += 1; 
      
      // Add the node in front of higher frequency list
      nextHigherFreqList->addFront(node); 
      
      // Update the 
      freqListMap[node->cnt] = nextHigherFreqList; 
      keyNode[node->key] = node;
  }
  
   int get(int key) {
       // Return the value if key exists
      if(keyNode.find(key) != keyNode.end()) {
          Node* node = keyNode[key]; // Get the node
          int val = node->value; // Get the value
          updateFreqListMap(node); // Update the frequency
          
          // Return the value
          return val; 
      }
      
      // Return -1 if key is not found
      return -1; 
   }
   
   void put(int key, int value) {
        /* If the size of Cache is 0, 
      no data-items can be inserted */
      if (maxSizeCache == 0) {
          return;
      }
      
      // If key already exists
      if(keyNode.find(key) != keyNode.end()) {
          
          // Get the node
          Node* node = keyNode[key]; 
          
          // Update the value
          node->value = value; 
          
          // Update the frequency
          updateFreqListMap(node); 
      }
      
      // Else if the key does not exist
      else {
          
          // If cache limit is reached
          if(curSize == maxSizeCache) {
              
              // Remove the least frequently used data-item
              List* list = freqListMap[minFreq]; 
              keyNode.erase(list->tail->prev->key); 
              
              // Update the frequency map 
              freqListMap[minFreq]->removeNode(
                  list->tail->prev
              );
              
              // Decrement the current size of cache
              curSize--; 
          }
          
          // Increment the current cache size
          curSize++; 
          
          // Adding new value to the cache
          minFreq = 1; // Set its frequency to 1
          
          // Create a dummy list
          List* listFreq = new List(); 
          
          // If the list already exist
          if(freqListMap.find(minFreq) != 
             freqListMap.end()) {
              
              // Update the pointer to already present list
              listFreq = freqListMap[minFreq]; 
          }
          
          // Create the node to store data-item
          Node* node = new Node(key, value); 
          
          // Add the node to dummy list
          listFreq->addFront(node);
          
          // Add the node to Hashmap
          keyNode[key] = node; 
          
          // Update the frequency list map 
          freqListMap[minFreq] = listFreq; 
      }
   }
};