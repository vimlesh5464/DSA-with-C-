#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {
        // constructor is empty
    }

    void push(int x) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push the new element into q1
        q1.push(x);

        // Move all elements back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;   // 30
    cout << "Pop: " << st.pop() << endl;           // 30
    cout << "Top element: " << st.top() << endl;   // 20
    cout << "Is empty? " << (st.empty() ? "Yes" : "No") << endl;

    st.pop();
    st.pop();
    cout << "Is empty after popping all? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}
