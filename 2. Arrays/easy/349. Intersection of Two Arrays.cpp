#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
//Union with Duplicates
vector<int> findUnion(vector<int>& a, vector<int>& b) {
  	unordered_set<int> st;  
  	
    // Put all elements of a[] in st
    for (int i = 0; i < a.size(); i++) 
      	st.insert(a[i]);
  	
  	// Put all elements of b[] in st
    for (int i = 0; i < b.size(); i++) 
      	st.insert(b[i]);
  	
    vector<int> res;                            
  	
  	// iterate through the set to 
  	// fill the result array 
  	for(auto it: st) 
      	res.push_back(it);
    
    return res;
}

int main() {
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> res = findUnion(a, b);
  
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";

    return 0;
}


// C++ program to find union of two arrays
// with distinct elements

#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
      vector<int> intersect(const vector<int> &A, const vector<int> &B) {
          int n = A.size();
          int m = B.size();
          
          vector<int> ans;
          if (A.empty() || B.empty()) return ans;
          
          vector<int> temp = B;
  
          for (int i = 0; i < n; i++) {
              for (int j = 0; j < m; j++) {
                  if (A[i] == temp[j]) {
                      ans.push_back(A[i]);
                      temp[j] = INT_MIN;
                      break;
                  }
              }
          }
          
          return ans;
      }
  };

int main() {

    vector<int> a = {1, 2, 3};
    vector<int> b = {5, 2, 7};

    vector<int> res = findUnion(a, b);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}


//1. Intersection with Duplicates
#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

//[Naive Approach] Time Complexity = O(n + m) and Space Complexity = O(min(n, m))
//(excluding the output vector ans, auxiliary space = O(1))
vector<int> intersect(vector<int>& A, vector<int>& B) {
  int n = A.size();
  int m = B.size();
  vector<int> ans;
  if(A.empty() || B.empty()){
      return ans;
  }
  int i = 0;
  int j = 0;
  while(i < n && j < m){
      if(A[i]==B[j]){
          ans.push_back(A[i]);
          i++;
          j++;
      }else if(A[i]<B[j]){
          i++;
      }else{
          j++;
      }
  }
  return ans;
}


//[Better Approach] Using Nested Loops and Hash Set - O(n × m) Time and O(n) Space
vector<int> intersect(vector<int>& a, vector<int>& b) {
  vector<int> res;

  unordered_map<int, int> seen;

  // Traverse through a[] and search every element
  // a[i] in b[]
  for (int i = 0; i < a.size(); i++) {
      for (int j = 0; j < b.size(); j++) {

          // If found, check if the element is already 
          // in the result to avoid duplicates
          if (a[i] == b[j] && seen.count(a[i]) == 0) {
              seen.insert({a[i], 1});
              res.push_back(a[i]);
          }
      }
  }

  return res;
}

//[Expected Approach 1] Using Two Hash Sets - O(n+m) Time and O(n) Space
vector<int> intersect(vector<int>& a, vector<int>& b) {
  
  // Put all elements of a[] in as
  unordered_set<int> as(a.begin(), a.end());  

  unordered_set<int> rs;                    
  vector<int> res;                            

  // Traverse through b[]
  for (int i = 0; i < b.size(); i++) {
    
      // If the element is in as and not yet in rs
      // a) Add it to the result set
      // b) Add it to the result array
      if (as.find(b[i]) != as.end() && 
          rs.find(b[i]) == rs.end()) {
          rs.insert(b[i]); 
          res.push_back(b[i]); 
      }
  }

  return res;
}

int main() {
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> res = intersect(a, b);
  
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";

    return 0;
}