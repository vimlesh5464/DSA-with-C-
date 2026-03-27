#include <iostream>
#include <string>
using namespace std;

class myQueue {
private:
    int* arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;

public:
    myQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    ~myQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = x;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    int front() {
        if (isEmpty()) return -1;
        return arr[frontIndex];
    }

    int size() {
        return count;
    }
};

int main() {
    int n;
    cout << "Enter the size of the queue: ";
    cin >> n;

    myQueue q(n);

    int qOps;
    cout << "Enter number of operations: ";
    cin >> qOps;

    cout << "Commands: enqueue x | dequeue | front | isempty | isfull | size\n";

    while (qOps--) {
        string cmd;
        cin >> cmd;

        if (cmd == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        }
        else if (cmd == "dequeue") {
            q.dequeue();
        }
        else if (cmd == "front") {
            cout << q.front() << endl;
        }
        else if (cmd == "isempty") {
            cout << (q.isEmpty() ? "true" : "false") << endl;
        }
        else if (cmd == "isfull") {
            cout << (q.isFull() ? "true" : "false") << endl;
        }
        else if (cmd == "size") {
            cout << q.size() << endl;
        }
        else {
            cout << "Invalid command\n";
        }
    }

    return 0;
}
