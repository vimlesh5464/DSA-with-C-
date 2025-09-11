// C++ program to rearrange positive and negative numbers alternately
// using rotation in array
#include <iostream>
#include <vector>
using namespace std;

//[Naive Approach] Using Rotation in array - O(n^2) Time and O(1) Space
// Function to right rotate the subarray between out-of-place
// element and next opposite sign element
void rightRotate(vector<int>& arr, int start, int end) {
    int temp = arr[end];
    for (int i = end; i > start; i--) {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}

// Function to rearrange the array
void rearrange(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        
        // Check if the current positive element is out of place
        if(arr[i] >= 0 && i % 2 == 1) {
          
            // Find the next negative element and rotate the subarray
            // between these two elements
        	for(int j = i + 1; j < n; j++) {
            	if(arr[j] < 0) {
                	rightRotate(arr, i, j);
              		break;
                }
            }
        }
      	
      	// Check if the current negative element is out of place
      	else if(arr[i] < 0 && i % 2 == 0){
        	
            // Find the next positive element and rotate the subarray
            // between these two elements
            for(int j = i + 1; j < n; j++) {
            	if(arr[j] >= 0) {
                	rightRotate(arr, i, j);
              		break;
                }
            }
        }
    }
}

//[Expected Approach] Using Two Pointers - O(n) Time and O(n) Space
void rearrange(vector<int>& arr) {
  vector<int> pos, neg;

  // Separate positive and negative numbers
  for (int i = 0; i < arr.size(); i++) {
      if (arr[i] >= 0)
          pos.push_back(arr[i]);
      else
          neg.push_back(arr[i]);
  }

  int posIdx = 0, negIdx = 0;
  int i = 0;

  // Place positive and negative numbers alternately
  // in the original array
  while (posIdx < pos.size() && negIdx < neg.size()) {
      if (i % 2 == 0)
          arr[i++] = pos[posIdx++];
      else 
          arr[i++] = neg[negIdx++];
  }

  // Append remaining positive numbers (if any)
  while (posIdx < pos.size())
      arr[i++] = pos[posIdx++];

  // Append remaining negative numbers (if any)
  while (negIdx < neg.size())
      arr[i++] = neg[negIdx++];
}

int main() {
    vector<int> arr = {1, 2, 3, -4, -1, 4};

    rearrange(arr);
	for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
  
    return 0;
}