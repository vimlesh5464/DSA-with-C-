#include<iostream>
#include<vector>
#include<string>
#include<algorithm> // Optional: For sort, but assume input is sorted

using namespace std;

// Corrected function to find the smallest letter strictly greater than the target.
// The array is assumed to be sorted and wraps around.
char greate(vector<char>& letters, char target){
    int n = letters.size();
    int l = 0;
    int h = n - 1;

    // Standard Binary Search to find the first element > target (or the insertion point)
    while(l <= h){
        int mid = l + (h - l) / 2;

        if(letters[mid] > target){
            // This could be the answer, but try to find an even smaller character
            // that is still greater than the target, so search the left half.
            h = mid - 1;
        } else {
            // letters[mid] <= target, so we must look in the right half
            l = mid + 1;
        }
    }
    
    // After the loop, 'l' will point to the index of the smallest element 
    // strictly greater than 'target'.
    // If all elements are <= target, 'l' will be equal to n. 
    // In this wrapping case, the answer is the first element (index 0).
    // The modulo operator handles both cases correctly.
    return letters[l % n]; 
}

int main(){
    char target;
    cout << "Enter the target character (e.g., 'k'): ";
    cin >> target;
    
    int n;
    cout << "Enter the number of characters in the vector: ";
    cin >> n;
    
    // It's crucial for the algorithm that the input vector is sorted.
    cout << "Enter " << n << " sorted characters (e.g., c f j): ";
    vector<char> letters;
    for( int i = 0; i < n; i++){
        char ch;
        cin >> ch;
        letters.push_back(ch);
    }
    
    // Call the function and print the result
    cout << "\nThe smallest letter greater than '" << target << "' is: ";
    cout << greate(letters, target) << endl;
    
    return 0;
}