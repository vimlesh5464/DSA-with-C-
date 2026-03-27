#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
  // check if substring has all unique characters
  bool isUnique(string s)
  {
    vector<bool> visited(256, false);

    for (char c : s)
        if (visited[c]){
          return false;
        }else{
          visited[c] = true;
        }
    return true;
  }

  // main function
  int lengthOfLongestSubstring(string s)
  {
    int n = s.size();
    int maxLen = 0;

    // generate all substrings
    for (int i = 0; i < n; i++)
    {
      string temp = "";
      for (int j = i; j < n; j++)
      {
        temp += s[j]; // substring ban rahi hai

        // check uniqueness
        if (isUnique(temp))
        {
          maxLen = max(maxLen, (int)temp.length());
        }
      }
    }
    return maxLen;
  }
};
class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int n = s.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
      vector<bool> visited(256, false); // har i ke liye fresh set

      for (int j = i; j < n; j++)
      {
        if (visited[s[j]])
        {
          break; // repeat mila → stop
        }

        visited[s[j]] = true;
        int currLen = j - i + 1;
        maxLen = max(maxLen, currLen);
      }
    }

    return maxLen;
  }
};
class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    vector<int> mpp(256, -1);

    int left = 0, right = 0;
    int n = s.size();
    int maxlen = 0;
    int len = 0;
    while (right < n)
    {
      if (mpp[s[right]] != -1)
      {
        if (mpp[s[right]] >= left)
        {
          left = mpp[s[right]] + 1;
        }
      }
      mpp[s[right]] = right;
      len = right - left + 1;
      maxlen = max(len, maxlen);
      right++;
    }
    return maxlen;
  }
};

int main()
{
  Solution sol;
  string str;
  cin >> str;
  cout << sol.lengthOfLongestSubstring(str);
  return 0;
}
