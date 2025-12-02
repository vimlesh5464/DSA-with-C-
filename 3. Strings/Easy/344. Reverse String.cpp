#include <iostream>
#include <string>
#include<vector>
using namespace std;
class Solution {
  public:
      void reverseString(vector<char>& s) {
          int left = 0, right = s.size() - 1;
  
          while (left < right) {
              swap(s[left], s[right]);
              left++;
              right--;
          }
      }
  };
  
  int main() {
      Solution sol;
  
      int n;
      cout << "Enter size of character array: ";
      cin >> n;
  
      vector<char> s(n);
      cout << "Enter characters:\n";
      for (int i = 0; i < n; i++) {
          cin >> s[i];
      }
  
      sol.reverseString(s);
  
      cout << "Reversed string: ";
      for (char c : s) {
          cout << c;
      }
      cout << endl;
  
      return 0;
  }
  