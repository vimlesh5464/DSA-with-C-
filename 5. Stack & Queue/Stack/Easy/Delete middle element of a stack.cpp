
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



// [Expected Approach 2] - Using Stack - O(n) Time and O(n) Space

//     Pop the elements above the middle element of the given stack 
//     and use a temp stack to store these popped elements. Then pop
//      the middle element and push the elements of the temp stack in the given stack.

void deleteMid(stack<int>& st)
{
    int n = st.size();
    stack<int> tempSt;
    int count = 0;

    while (count < n / 2) {
        int c = st.top();
        st.pop();
        tempSt.push(c);
        count++;
    }

    st.pop();

    while (!tempSt.empty()) {
        st.push(tempSt.top());
        tempSt.pop();
    }
}

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