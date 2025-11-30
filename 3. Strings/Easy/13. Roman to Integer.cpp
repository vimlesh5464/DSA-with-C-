#include <iostream>
#include <string>
#include<unordered_map>
using namespace std;
class Solution {
  public:
      int romanToInt(string s) {
          unordered_map<char, int> roman = {
              {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
              {'C', 100}, {'D', 500}, {'M', 1000}
          };
  
          int total = 0;
          for (int i = 0; i < s.size(); ++i) {
              int curr = roman[s[i]];
              int next = roman[s[i + 1]];
  
              if (i + 1 < s.size() && curr < next) {
                  total -= curr;
              } else {
                  total += curr;
              }
          }
  
          return total;
      }
  };
  int main() {
    string s;
    cin >> s;  // input Roman numeral (like "MCMXCIV")

    Solution obj;
    cout << obj.romanToInt(s) << endl;

    return 0;
}
