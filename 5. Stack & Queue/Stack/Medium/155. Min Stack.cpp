#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class MinStack {
private:
    stack<int> st;      // normal stack
    stack<int> minSt;   // stack to track minimums

public:
    MinStack() {}

    void push(int val) {
        st.push(val);

        // Push into min stack if empty or val <= current min
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "Current Min: " << minStack.getMin() << endl; // -3
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;            // 0
    cout << "Current Min: " << minStack.getMin() << endl; // -2

    return 0;
}
