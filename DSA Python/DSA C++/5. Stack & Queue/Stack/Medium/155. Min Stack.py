# 155. Min Stack.py - Python skeleton converted from C++

# Original C++ code:
# // esign a stack that supports push, pop, top, and retrieving the minimum element in constant time.
# 
# // Implement the MinStack class:
# 
# //     MinStack() initializes the stack object.
# //     void push(int val) pushes the element val onto the stack.
# //     void pop() removes the element on the top of the stack.
# //     int top() gets the top element of the stack.
# //     int getMin() retrieves the minimum element in the stack.
# 
# // You must implement a solution with O(1) time complexity for each function.
# // Example 1:
# // Input
# // ["MinStack","push","push","push","getMin","pop","top","getMin"]
# // [[],[-2],[0],[-3],[],[],[],[]]
# 
# // Output
# // [null,null,null,null,-3,null,0,-2]
# 
# // Explanation
# // MinStack minStack = new MinStack();
# // minStack.push(-2);
# // minStack.push(0);
# // minStack.push(-3);
# // minStack.getMin(); // return -3
# // minStack.pop();
# // minStack.top();    // return 0
# // minStack.getMin(); // return -2
# 
# // Constraints:
# //     -231 <= val <= 231 - 1
# //     Methods pop, top and getMin operations will always be called on non-empty stacks.
# //     At most 3 * 104 calls will be made to push, pop, top, and getMin.
# 
#  
# #include<iostream>
# #include<vector>
# #include<stack>
# using namespace std;
# 
# class MinStack {
# private:
#     stack<int> st;      // normal stack
#     stack<int> minSt;   // stack to track minimums
# 
# public:
#     MinStack() {}
# 
#     void push(int val) {
#         st.push(val);
# 
#         // Push into min stack if empty or val <= current min
#         if (minSt.empty() || val <= minSt.top()) {
#             minSt.push(val);
#         }
#     }
# 
#     void pop() {
#         if (st.top() == minSt.top()) {
#             minSt.pop();
#         }
#         st.pop();
#     }
# 
#     int top() {
#         return st.top();
#     }
# 
#     int getMin() {
#         return minSt.top();
#     }
# };
# 
# int main() {
#     MinStack minStack;
#     minStack.push(-2);
#     minStack.push(0);
#     minStack.push(-3);
# 
#     cout << "Current Min: " << minStack.getMin() << endl; // -3
#     minStack.pop();
#     cout << "Top: " << minStack.top() << endl;            // 0
#     cout << "Current Min: " << minStack.getMin() << endl; // -2
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
