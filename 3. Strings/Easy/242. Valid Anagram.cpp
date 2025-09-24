#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> count(26, 0); // for lowercase a-z

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }

        return true;
    }
};

// Driver code for testing
int main() {
    Solution sol;

    string s1 = "anagram", t1 = "nagaram";
    string s2 = "rat", t2 = "car";
    string s3 = "listen", t3 = "silent";

    cout << (sol.isAnagram(s1, t1) ? "true" : "false") << endl; // true
    cout << (sol.isAnagram(s2, t2) ? "true" : "false") << endl; // false
    cout << (sol.isAnagram(s3, t3) ? "true" : "false") << endl; // true

    return 0;
}
