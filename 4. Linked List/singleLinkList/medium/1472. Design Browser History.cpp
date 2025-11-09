#include <iostream>
#include<vector>
#include<string>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class BrowserHistory {
  public:
      vector<string> history;
      int cur;      // current page index
      int last;     // last valid page index (for forward reset)
  
      BrowserHistory(string homepage) {
          history.push_back(homepage);
          cur = 0;
          last = 0;
      }
  
      void visit(string url) {
          // Move pointer
          cur++;
          if (cur == history.size()) {
              history.push_back(url);
          } else {
              history[cur] = url;
          }
  
          // When we visit, forward history is removed
          last = cur;
      }
  
      string back(int steps) {
          cur = max(0, cur - steps);
          return history[cur];
      }
  
      string forward(int steps) {
          cur = min(last, cur + steps);
          return history[cur];
      }
  };
  int main() {
    BrowserHistory* obj = new BrowserHistory("leetcode.com");

    obj->visit("google.com");
    obj->visit("facebook.com");
    obj->visit("youtube.com");

    cout << obj->back(1) << endl;     // facebook.com
    cout << obj->back(1) << endl;     // google.com
    cout << obj->forward(1) << endl;  // facebook.com

    obj->visit("linkedin.com");
    cout << obj->forward(2) << endl;  // linkedin.com
    cout << obj->back(2) << endl;     // google.com
    cout << obj->back(7) << endl;     // leetcode.com

    return 0;
}
