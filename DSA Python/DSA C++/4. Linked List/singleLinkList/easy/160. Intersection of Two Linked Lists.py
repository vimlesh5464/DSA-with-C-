# 160. Intersection of Two Linked Lists.py - Python skeleton converted from C++

# Original C++ code:
# // Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
# 
# // For example, the following two linked lists begin to intersect at node c1:
# 
# // The test cases are generated such that there are no cycles anywhere in the entire linked structure.
# 
# // Note that the linked lists must retain their original structure after the function returns.
# 
# // Custom Judge:
# 
# // The inputs to the judge are given as follows (your program is not given these inputs):
# 
# //     intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
# //     listA - The first linked list.
# //     listB - The second linked list.
# //     skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
# //     skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
# 
# // The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.
# 
#  
# 
# // Example 1:
# 
# // Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
# // Output: Intersected at '8'
# // Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
# // From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
# // - Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.
# 
# // Example 2:
# 
# // Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
# // Output: Intersected at '2'
# // Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
# // From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
# 
# // Example 3:
# 
# // Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
# // Output: No intersection
# // Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
# // Explanation: The two lists do not intersect, so return null.
# 
#  
# 
# // Constraints:
# 
# //     The number of nodes of listA is in the m.
# //     The number of nodes of listB is in the n.
# //     1 <= m, n <= 3 * 104
# //     1 <= Node.val <= 105
# //     0 <= skipA <= m
# //     0 <= skipB <= n
# //     intersectVal is 0 if listA and listB do not intersect.
# //     intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.
# 
#  
# // Follow up: Could you write a solution that runs in O(m + n) time and use only O(1) memory?
# #include <iostream>
# #include<unordered_set>
# using namespace std;
# 
# // Linked list node
# struct Node {
#     int data;
#     Node* next;
#     Node(int val) {
#         data = val;
#         next = NULL;
#     }
# };
# 
# // Insert node at end
# void insert(Node*& head, int val) {
#     Node* newNode = new Node(val);
#     if (head == NULL) {
#         head = newNode;
#         return;
#     }
#     Node* temp = head;
#     while (temp->next != NULL) {
#         temp = temp->next;
#     }
#     temp->next = newNode;
# }
# 
# // Print linked list
# void printList(Node* head) {
#     Node* temp = head;
#     while (temp != NULL) {
#         cout << temp->data << " -> ";
#         temp = temp->next;
#     }
#     cout << "NULL" << endl;
# }
# 
# // Solution class
# class Solution {
# public:
#     Node* getIntersectionNode(Node* headA, Node* headB) {
#         if (!headA || !headB) return NULL;
# 
#         Node* a = headA;
#         Node* b = headB;
# 
#         while (a != b) {
#             a = (a == NULL) ? headB : a->next;
#             b = (b == NULL) ? headA : b->next;
#         }
# 
#         return a; // intersection node or NULL
#     }
# };
# 
# // Solution class
# class Solution {
#   public:
#       Node* getIntersectionNode(Node* headA, Node* headB) {
#           Node* temp = headA;
#           while(headB!=NULL){
#             while(temp!=NULL){
#               if(temp==headB){
#                 return headB;
#               }
#               temp=temp->next;
#             }
#             headB=headB->next;
#           }
#           return NULL;
#       }
#   };
#   
#   class Solution {
#     public:
#         Node* getIntersectionNode(Node* headA, Node* headB) {
#           unordered_set<Node*> st;
#           while(headA != NULL) {
#              st.insert(headA);
#              headA = headA->next;
#           }
#           while(headB != NULL) {
#               if(st.find(headB) != st.end()) return headB;
#               headB = headB->next;
#           }
#           return NULL;
#         }
#     };
#     
# // Driver code
# int main() {
#     // Create two linked lists
#     Node* headA = NULL;
#     Node* headB = NULL;
# 
#     // List A: 4 -> 1 -> 8 -> 4 -> 5
#     insert(headA, 4);
#     insert(headA, 1);
#     Node* inter = new Node(8);
#     headA->next->next = inter;
#     inter->next = new Node(4);
#     inter->next->next = new Node(5);
# 
#     // List B: 5 -> 6 -> 1 -> (intersect at 8)
#     insert(headB, 5);
#     insert(headB, 6);
#     insert(headB, 1);
#     headB->next->next->next = inter; // intersection link
# 
#     cout << "List A: ";
#     printList(headA);
#     cout << "List B: ";
#     printList(headB);
# 
#     Solution sol;
#     Node* result = sol.getIntersectionNode(headA, headB);
# 
#     if (result)
#         cout << "Intersection Node: " << result->data << endl;
#     else
#         cout << "No Intersection" << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
