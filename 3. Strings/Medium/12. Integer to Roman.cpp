#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
  public:
      string intToRoman(int num) {
          vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
          vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  
          string result = "";
  
          for (int i = 0; i < values.size(); i++) {
              while (num >= values[i]) {
                  result += romans[i];
                  num -= values[i];
              }
          }
  
          return result;
      }
  };
 
  
  class Solution {
  public:
      string intToRoman(int num) {
          // Hash table for fast lookup
          unordered_map<int, string> roman = {
              {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
              {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
              {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},
              {1000, "M"}
          };
  
          // Sorted values (descending)
          vector<int> values = {
              1000, 900, 500, 400, 100, 90, 
              50, 40, 10, 9, 5, 4, 1
          };
  
          string result = "";
  
          for (int v : values) {
              while (num >= v) {
                  result += roman[v];   // hash table lookup
                  num -= v;
              }
          }
  
          return result;
      }
  };
  
  int main() {
      int n;
      cin >> n;
  
      Solution obj;
      cout << obj.intToRoman(n) << endl;
  
      return 0;
  }
    