# Sort a stack using recursion.py - Python skeleton converted from C++

# Original C++ code:
# // Given a stack of integers st[]. Sort the stack in ascending order (smallest element at the bottom and largest at the top).
# 
# // Examples:
# 
# // Input: st[] = [1, 2, 3]
# // Output: [3, 2, 1]
# // Explanation: The stack is already sorted in ascending order.
# 
# // Input: st[] = [41, 3, 32, 2, 11]
# // Output: [41, 32, 11, 3, 2]
# // Explanation: After sorting, the smallest element (2) is at the bottom and the largest element (41) is at the top.
# 
# // Constraints:
# // 1 ≤ st.size() ≤ 103
# // 0 ≤ stack element ≤ 103
# 
# #include <iostream>
# #include <stack>
# #include <vector>
# using namespace std;
# 
# // Function to insert element in sorted order
# void insert(stack<int>& s, int temp) {
#     // Base case: if the stack is empty or temp is larger than the top element
#     if (s.empty() || s.top() <= temp) {
#         s.push(temp);
#         return;
#     }
#     
#     // Otherwise, pop the top element and recursively insert
#     int val = s.top();
#     s.pop();
#     insert(s, temp);
#     
#     // Push the popped element back
#     s.push(val);
# }
# 
# // Function to sort the stack
# void sortStack(stack<int>& s) {
#     if (!s.empty()) {
#         int temp = s.top();
#         s.pop();
#         
#         sortStack(s);
#         
#         insert(s, temp);
#     }
# }
# 
# // Main function
# int main() {
#     stack<int> s;
#     s.push(4);
#     s.push(1);
#     s.push(3);
#     s.push(2);
# 
#     sortStack(s);
# 
#     // Print the sorted stack
#     cout << "Sorted stack (descending order): ";
#     while (!s.empty()) {
#         cout << s.top() << " ";
#         s.pop();
#     }
#     return 0;
# }
# 
# 
# 
# 

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
