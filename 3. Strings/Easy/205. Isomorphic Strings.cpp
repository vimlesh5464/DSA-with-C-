#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
  public:
      bool isIsomorphic(string s, string t) {
          if (s.length() != t.length()) return false;
  
          unordered_map<char, char> mp1, mp2;
  
          for (int i = 0; i < s.length(); i++) {
              char a = s[i], b = t[i];
  
              if (mp1.find(a)!=mp1.end() && mp1[a] != b) return false;
              if (mp2.find(b) !=mp2.end() && mp2[b] != a) return false;
  
              mp1[a] = b;
              mp2[b] = a;
          }
          return true;
      }
  };
  int main() {
    Solution obj;
    string s, t;

    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    if (obj.isIsomorphic(s, t))
        cout << "Strings are Isomorphic" << endl;
    else
        cout << "Strings are NOT Isomorphic" << endl;

    return 0;
}