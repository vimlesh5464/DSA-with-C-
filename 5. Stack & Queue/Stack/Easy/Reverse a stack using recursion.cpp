// You are given a stack st[]. You have to reverse the stack.

// Note: The input array represents the stack from bottom to 
//top (last element is the top). The output is displayed by printing 
//elements from top to bottom after reversal.

// Examples:

// Input: st[] = [1, 2, 3, 4]
// Output: [1, 2, 3, 4]
// Explanation: After reversing, the elements of stack are in opposite order.

// Input: st[] = [3, 2, 1]
// Output: [3, 2, 1]
// Explanation: After reversing, the elements of stack are in opposite order.

// Constraints:
// 1 ≤ st.size() ≤ 100
// 0 ≤ stack element ≤ 100
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &st, int val) {
    // If stack is empty, push the value
    if (st.empty()) {
        st.push(val);
        return;
    }

    // Pop the top element
    int topVal = st.top();
    st.pop();

    // Recurse for the rest of the stack
    insertAtBottom(st, val);

    // Push the popped element back
    st.push(topVal);
}

// Function to reverse the stack
void reverseStack(stack<int> &st) {
    // Base case: If stack is empty, return
    if (st.empty()) return;

    // Pop the top element
    int topVal = st.top();
    st.pop();

    // Recursively reverse the remaining stack
    reverseStack(st);

    // Insert the popped element at the bottom
    insertAtBottom(st, topVal);
}

int main() {
    // Create a sample stack
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);

    // Reverse the stack
    reverseStack(st);

    // Print the reversed stack
    cout << "Reversed Stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}