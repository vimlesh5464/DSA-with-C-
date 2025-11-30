#include<iostream>
#include <string>
#include<stack>
using namespace std;
class Solution {
  public:
      int minSwaps(string s) {
          stack<char> st;
          int unmatchedClosing = 0;
  
          for (char c : s) {
              if (c == '[') {
                  st.push(c);
              } else { // c == ']'
                  if (!st.empty() && st.top() == '[') {
                      st.pop(); // matched pair
                  } else {
                      unmatchedClosing++; // unmatched ']'
                  }
              }
          }
  
          // Each swap fixes 2 brackets
          return (unmatchedClosing + 1) / 2;
      }
  };
class Solution {
public:
    int minSwaps(string s) {
        int count = 0; // balance of '['
        int maxUnbalanced = 0;

        for (char c : s) {
            if (c == '[') count++;
            else count--; // c == ']'

            if (count < 0) maxUnbalanced = max(maxUnbalanced, -count);
        }

        return (maxUnbalanced + 1) / 2; // ceil division
    }
};

// ---------------- MAIN ----------------
int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.minSwaps(s) << endl;

    return 0;
}
