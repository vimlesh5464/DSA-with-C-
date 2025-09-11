#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {
        // empty constructor
    }

    // Costly push: O(n)
    void push(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element into s1
        s1.push(x);

        // Move everything back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int val = s1.top();  // front element (because we reversed in push)
        s1.pop();
        return val;
    }

    int peek() {
        if (s1.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return s1.top();  // front element
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl;   // 10
    cout << "Pop: " << q.pop() << endl;              // 10
    cout << "Front element: " << q.peek() << endl;   // 20
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    q.pop();
    q.pop();
    cout << "Is empty after popping all? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
