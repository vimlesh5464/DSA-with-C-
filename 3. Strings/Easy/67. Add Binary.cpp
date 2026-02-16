#include <iostream>
#include <string>
using namespace std;
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;
        string result = "";
        
        while(i >= 0 || j >= 0 || carry){
            
            int sum = carry;
            
            if(i >= 0){
                sum += s1[i] - '0';
                i--;
            }
            
            if(j >= 0){
                sum += s2[j] - '0';
                j--;
            }
            
            result += (sum % 2) + '0';
            carry = sum / 2;
        }
        
        reverse(result.begin(), result.end());
        
        // Remove leading zeros
        while(result.size() > 1 && result[0] == '0'){
            result.erase(result.begin());
        }
        
        return result;
    }
};