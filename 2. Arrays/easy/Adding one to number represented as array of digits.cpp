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

  int n = arr.size();
        
        // Start from last digit
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] < 9) {
                arr[i]++;     // no carry, done
                return arr;
            }
            arr[i] = 0;       // carry forward
        }

        // If we reach here, all digits were 9
        arr.insert(arr.begin(), 1);
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