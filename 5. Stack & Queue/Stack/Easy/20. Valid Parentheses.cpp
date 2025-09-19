#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

//[Approach 1] Using Stack - O(n) Time and O(n) Space
bool isBalanced(string& s) {
   
    stack<char> st; 
   
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        
        else if (c == ')' || c == '}' || c == ']') {
            
            // No opening bracket
            if (st.empty()) return false; 
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
            
            // Pop matching opening bracket
            st.pop(); 
        }
    }
    
    // Balanced if stack is empty
    return st.empty(); 
}

//[Approach 2] Without using Stack - O(n) Time and O(1) Space
bool isBalanced(string& s) {
    
  // stack top index in string
  int top = -1;
  for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
          
          // push opening bracket
          s[++top] = s[i]; 
      } 
      else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
          
          // no opening bracket
          if (top == -1) return false; 
          if ((s[i] == ')' && s[top] != '(') ||
              (s[i] == '}' && s[top] != '{') ||
              (s[i] == ']' && s[top] != '[')) {
              return false;
          }
          top--;
      }
  }
  
  // balanced if stack empty
  return top == -1; 
}

int main() {
    string s="[()()]{}";
    cout<<(isBalanced(s)?"true":"false");
    return 0;
}