#include<iostream>
#include <string>
#include<queue>
using namespace std;

class Solution {
  public:
      void rearrangeQueue(queue<int> &q) {
          int n = q.size();
          if (n <= 1) return;
  
          queue<int> q1, q2;
  
          // Step 1: split queue into two halves
          for (int i = 0; i < n / 2; i++) {
              q1.push(q.front());
              q.pop();
          }
  
          while (!q.empty()) {
              q2.push(q.front());
              q.pop();
          }
  
          // Step 2: interleave q1 and q2
          while (!q1.empty() && !q2.empty()) {
              q.push(q1.front());
              q1.pop();
  
              q.push(q2.front());
              q2.pop();
          }
      }
  };

  int main() {
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    Solution obj;
    obj.rearrangeQueue(q);

    // Print rearranged queue
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
  