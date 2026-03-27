#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
  public:
      vector<string> findRepeatedDnaSequences(string s) {
          unordered_set<string> seen;
          unordered_set<string> repeated;
          vector<string> result;
  
          if (s.length() < 10) return result;
  
          for (int i = 0; i <= s.length() - 10; i++) {
              string sub = s.substr(i, 10);
  
              if (seen.count(sub))
                  repeated.insert(sub);
              else
                  seen.insert(sub);
          }
  
          return vector<string>(repeated.begin(), repeated.end());
      }
  };
  
  // Time: O(n)

  // Space: O(n)
vector<string> findRepeatedDnaSequences(string s) {
    vector<string> result;
    if (s.length() < 10) return result;

    unordered_map<char, int> mp = {
        {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}
    };

    unordered_set<int> seen, repeated;
    int hash = 0;
    int mask = (1 << 20) - 1; // keep last 20 bits

    for (int i = 0; i < s.length(); i++) {
        hash = ((hash << 2) | mp[s[i]]) & mask;

        if (i >= 9) {
            if (seen.count(hash))
                repeated.insert(hash);
            else
                seen.insert(hash);
        }
    }

    // Decode hash back to string
    for (int h : repeated) {
        string seq(10, ' ');
        for (int i = 9; i >= 0; i--) {
            seq[i] = "ACGT"[h & 3];
            h >>= 2;
        }
        result.push_back(seq);
    }

    return result;
}

int main() {
    string s;
    cin >> s;

    vector<string> ans = findRepeatedDnaSequences(s);

    for (string &seq : ans) {
        cout << seq << " ";
    }

    return 0;
}
