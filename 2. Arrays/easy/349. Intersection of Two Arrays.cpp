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

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    vector<int> res = a;

    // Traverse through b[] and search every element
    // b[i] in a[]
    for (int i = 0; i < b.size(); i++) {

        // check if the element was present in a[]
        // to avoid duplicates
        int j;
        for (j = 0; j < a.size(); j++) {
            if (a[j] == b[i])
                break;
        }

        // if not already present then
        // add it to result
        if (j == a.size()) {
            res.push_back(b[i]);
        }
    }
    return res;
}

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

//[Naive Approach] Using Triple Nested Loops - O(n × n × m) Time and O(1) Space
vector<int> intersect(vector<int>& a, vector<int>& b) {
    vector<int> res;

    // Traverse through a[] and search every element
    // a[i] in b[]
    for (int i = 0; i < a.size(); i++) {    
        for (int j = 0; j < b.size(); j++) {
          
            // If found, check if the element is already 
            // in the result to avoid duplicates
            if (a[i] == b[j]) { 
                int k;
                for (k = 0; k < res.size(); k++) 
                    if (res[k] == a[i]) 
                        break;
                if (k == res.size()) {
                    res.push_back(a[i]);
                }
            }
        }
    }

    return res;
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