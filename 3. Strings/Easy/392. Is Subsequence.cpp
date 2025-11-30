#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // pointer for s
        int j = 0; // pointer for t
        
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++; // match found in order
            }
            j++; // always move in t
        }
        
        return i == s.size(); // all characters matched?
    }
};

int main() {
    string s, t;
    
    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;
    
    Solution obj;
    bool result = obj.isSubsequence(s, t);
    
    if(result) {
        cout << "YES, s is a subsequence of t\n";
    } else {
        cout << "NO, s is NOT a subsequence of t\n";
    }

    return 0;
}
