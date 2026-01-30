#include<iostream>
#include<stack>
#include<string>
 using namespace std;

// | Approach          | Time | Space | Notes                           |
// | ----------------- | ---- | ----- | ------------------------------- |
// | **Stack**         | O(n) | O(n)  | More intuitive, but extra stack |
// | **Depth Counter** | O(n) | O(n)  | Cleaner, faster, preferred      |


class Solution {
  public:
      string removeOuterParentheses(string s) {
          stack<char> st;
          string ans = "";
  
          for (char c : s) {
              if (c == '(') {
                  if (!st.empty())
                      ans += c;
                  st.push(c);
              } else { // ')'
                  st.pop();
                  if (!st.empty())
                      ans += c;
              }
          }
          return ans;
      }
  };

  class Solution {
    public:
        string removeOuterParentheses(string s) {
            string result = "";
            int depth = 0;
    
            for (char c : s) {
                if (c == '(') {
                    if (depth > 0) result += c;
                    depth++;
                } else {
                    depth--;
                    if (depth > 0) result += c;
                }
            }
            return result;
        }
    };
  int main() {
    Solution obj;
    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    cout << "Result: " << obj.removeOuterParentheses(s) << endl;
    return 0;
}  