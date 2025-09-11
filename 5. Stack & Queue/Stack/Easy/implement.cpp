#include <iostream>
using namespace std;

class Stack {
    int top;
    int arr[100]; // fixed size stack

public:
    Stack() { top = -1; }

    void push(int x) {
        if (top >= 99) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = x;
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
        } else {
            top--;
        }
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty\n";
            return -1;
        } else {
            return arr[top];
        }
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    cout << "Top element after pop: " << s.peek() << endl;
    return 0;
}
