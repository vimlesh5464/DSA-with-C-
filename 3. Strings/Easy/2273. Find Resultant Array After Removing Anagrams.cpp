// Approach 
// step 1->  create vector
//step 2-> initialized two variable curr and prv
// step 3-> in prev store  first element and after sort 
// step 4-> iterate whole string 
//step 5-> take curr element and after that sort
// step 6-> compare curr and prev 
// step 7-> if equal skip nahi to add in vector

#include <iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
  public:
      vector<string> removeAnagrams(vector<string>& words) {
          vector<string> ans;
          if (words.empty()) return ans;
  
          ans.push_back(words[0]); // keep first word
          string prevSorted = words[0];
          sort(prevSorted.begin(), prevSorted.end());
  
          for (int i = 1; i < words.size(); i++) {
              string currSorted = words[i];
              sort(currSorted.begin(), currSorted.end());
  
              if (currSorted != prevSorted) {
                  ans.push_back(words[i]);  // keep word if not an anagram
                  prevSorted = currSorted;
              }
          }
  
          return ans;
      }
  };
  