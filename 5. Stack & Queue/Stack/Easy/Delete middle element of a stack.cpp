// Given a stack s, delete the middle element of the stack without using any additional data structure.

//     Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from the bottom of the stack.

// Note: The output shown by the compiler is the stack from top to bottom.

// Examples:

// Input: s = [10, 20, 30, 40, 50]
// Output: [50, 40, 20, 10]
// Explanation: The bottom-most element will be 10 and the top-most element will be 50. Middle element will be element at index 3 from bottom, which is 30. Deleting 30, stack will look like {10 20 40 50}.

// Input: s = [10, 20, 30, 40]
// Output: [40, 30, 10]
// Explanation: The bottom-most element will be 10 and the top-most element will be 40. Middle element will be element at index 2 from bottom, which is 20. Deleting 20, stack will look like {10 30 40}.

// Input: s = [5, 8, 6, 7, 6, 6, 5, 10, 12, 9]
// Output: [9, 12, 10, 5, 6, 7, 6, 8, 5]

// Constraints:
// 2 ≤ element of stack ≤ 105
// 2 ≤ s.size() ≤ 104

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//Approach - Using Vector - O(n) Time and O(n) Space
// The idea for this approach is that we just put all the elements of stack into a vector,
//  then traverse over the vector and push the elements back into stack, ignoring the mid
//   element for even (n/2) and for odd (ceil(n/2)).
void deleteMid(stack<int>& st, int size) {
    // Use a vector to store stack elements
    vector<int> v;
    while(!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }

    // Find the middle index
    int mid = size / 2;

    // Remove the middle element
    v.erase(v.begin() + mid);

    // Push elements back to the stack
    for(int i = v.size() - 1; i >= 0; i--) {
        st.push(v[i]);
    }
}

void deleteMiddle(stack<int>& st, int k) {
  // Base case: middle element
  if (k == 1) {
      st.pop();
      return;
  }

  int temp = st.top();
  st.pop();

  // Recursive call
  deleteMiddle(st, k - 1);

  // Push back
  st.push(temp);
}
//[Expected Approach 1] - Using Recursion - O(n) Time and O(n) Space
// Remove elements of the stack recursively until the count of removed
//  elements becomes half the initial size of the stack, now the top element
//   is the middle element thus pop it and push the previously removed elements in the reverse order.



// [Expected Approach 2] - Using Stack - O(n) Time and O(1) Space

//     Pop the elements above the middle element of the given stack 
//     and use a temp stack to store these popped elements. Then pop
//      the middle element and push the elements of the temp stack in the given stack.

class Solution {
  public:
  
    void solve(stack<int>& st, int curr, int mid) {
        // Base case: reached middle element
        if(curr == mid) {
            st.pop();   // delete middle
            return;
        }
        
        int top = st.top();
        st.pop();
        
        // Recursive call
        solve(st, curr + 1, mid);
        
        // Push back after recursion
        st.push(top);
    }

    void deleteMid(stack<int>& st) {
        int n = st.size();
        int mid = n / 2;
        
        solve(st, 0, mid);
    }
};
int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    int size = st.size();

    deleteMid(st, size);

    while (!st.empty()) {
        int p = st.top();
        st.pop();
        cout << p << " ";
    }
    
    return 0;
}