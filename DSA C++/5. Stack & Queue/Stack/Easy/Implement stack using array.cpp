#include <iostream>
using namespace std;

class myStack {
private:
    int* arr;
    int topIndex;
    int capacity;

public:
    // Constructor
    myStack(int n) {
        capacity = n;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Destructor
    ~myStack() {
        delete[] arr;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

    void push(int x) {
        if (!isFull()) {
            arr[++topIndex] = x;
        }
    }

    void pop() {
        if (!isEmpty()) {
            topIndex--;
        }
    }

    int peek() {   // <-- use peek() instead of top()
        if (isEmpty()) return -1;
        return arr[topIndex];
    }

    int size() {
        return topIndex + 1;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements to push: ";
    cin >> n;

    myStack st(n);

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    cout << "Stack elements (top to bottom): ";
    while (!st.isEmpty()) {
        cout << st.peek() << " ";  // <-- changed from st.top() to st.peek()
        st.pop();
    }
    cout << endl;

    return 0;
}
