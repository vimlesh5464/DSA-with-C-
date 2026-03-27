// Implement a first in first out (FIFO) queue using only two stacks. 
//The implemented queue should support all the functions of a normal queue 
//(push, peek, pop, and empty).

// Implement the MyQueue class:

//     void push(int x) Pushes element x to the back of the queue.
//     int pop() Removes the element from the front of the queue and returns it.
//     int peek() Returns the element at the front of the queue.
//     boolean empty() Returns true if the queue is empty, false otherwise.

// Notes:

//     You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
//     Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

 

// Example 1:

// Input
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 1, 1, false]

// Explanation
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false

 

// Constraints:

//     1 <= x <= 9
//     At most 100 calls will be made to push, pop, peek, and empty.
//     All the calls to pop and peek are valid.


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
