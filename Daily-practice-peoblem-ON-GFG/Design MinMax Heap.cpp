#include <iostream>
#include<vector>
#include <queue> 
#include <utility> 
using namespace std;

class SpecialQueue {
    queue<int> q;
    deque<int> minQ, maxQ;

  public:
    void enqueue(int x) {
        q.push(x);

        // Maintain increasing order for minQ
        while (!minQ.empty() && minQ.back() > x) {
            minQ.pop_back();
        }
        minQ.push_back(x);

        // Maintain decreasing order for maxQ
        while (!maxQ.empty() && maxQ.back() < x) {
            maxQ.pop_back();
        }
        maxQ.push_back(x);
    }

    void dequeue() {
        if (q.empty()) return;

        int val = q.front();
        q.pop();

        if (!minQ.empty() && minQ.front() == val) {
            minQ.pop_front();
        }
        if (!maxQ.empty() && maxQ.front() == val) {
            maxQ.pop_front();
        }
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        return minQ.front();
    }

    int getMax() {
        return maxQ.front();
    }
};

// ---------------- Driver code ----------------
int main() {
    int q;
    cin >> q;
    vector<vector<int>> queries(q);
    
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            queries[i] = {type, x};
        } else {
            queries[i] = {type};
        }
    }
    
    SpecialQueue sq;
    vector<int> output;
    
    for (auto &query : queries) {
        if (query[0] == 1) {
            sq.enqueue(query[1]);
        } else if (query[0] == 2) {
            sq.dequeue();
        } else if (query[0] == 3) {
            output.push_back(sq.getFront());
        } else if (query[0] == 4) {
            output.push_back(sq.getMin());
        } else if (query[0] == 5) {
            output.push_back(sq.getMax());
        }
    }
    
    for (int val : output) cout << val << " ";
    cout << endl;
    
    return 0;
}
