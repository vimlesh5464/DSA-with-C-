#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//[Approach] Adjacent Pair Swapping Method

//Time Complexity: O(n), a single pass swaps adjacent pairs.
//Auxiliary Space: O(1), in-place swaps use no extra storage.
void sortInWave(vector<int> &arr){
    
    int n = arr.size();

    // swap adjacent elements to create 
    // wave pattern
    for (int i = 0; i < n - 1; i += 2){
        swap(arr[i], arr[i + 1]);
    }
}


int main(){
    
    vector<int> arr = {1, 2, 3, 4, 5};
    sortInWave(arr);
    for (int i=0; i<arr.size(); i++)
       cout << arr[i] << " ";
    return 0;
}