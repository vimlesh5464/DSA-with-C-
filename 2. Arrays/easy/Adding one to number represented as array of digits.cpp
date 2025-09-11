// C++ program to add 1 to a
// number represented as an array
#include <iostream>
#include <vector>
using namespace std;

//[Approach - 1] - Using Carry - O(n) Time and O(1) Space
vector<int> addOne(vector<int> &arr) {

  
    int carry = 1;

    for(int i = arr.size() - 1; i >= 0; i--) {
        int sum = arr[i] + carry;
        arr[i] = sum % 10;
        carry = sum / 10;
    }

    if(carry) {
        arr.insert(arr.begin(), carry);
    }

    return arr;
}

//[Approach - 2] - O(n) Time and O(1) Space
vector<int> addOne(vector<int> &arr) {

  // initialize an index to end of array
  int index = arr.size() - 1;

  // while the index is valid and the value
  // at index is 9
  while (index >= 0 && arr[index] == 9)
      arr[index--] = 0;

  // if index < 0 (if all arr were 9)
  if (index < 0)

      // insert an one at the beginning of the vector
      arr.insert(arr.begin(), 1, 1);

  // else increment the value at [index]
  else
      arr[index]++;

  return arr;
}


int main() {
    vector<int> arr = {9, 9, 9};
    vector<int> res = addOne(arr);
    for(auto i:res) {
        cout << i;
    }
    return 0;
}