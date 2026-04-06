// You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

// Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

 

// Example 1:

// Input: letters = ["c","f","j"], target = "a"
// Output: "c"
// Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.

// Example 2:

// Input: letters = ["c","f","j"], target = "c"
// Output: "f"
// Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.

// Example 3:

// Input: letters = ["x","x","y","y"], target = "z"
// Output: "x"
// Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].

 

// Constraints:

//     2 <= letters.length <= 104
//     letters[i] is a lowercase English letter.
//     letters is sorted in non-decreasing order.
//     letters contains at least two different characters.
//     target is a lowercase English letter.

#include<iostream>
#include<vector>
#include<string>
#include<algorithm> // Optional: For sort, but assume input is sorted

using namespace std;
class Solution {
  public:
      char nextGreatestLetter(vector<char>& letters, char target) {
          for(char ch : letters) {
              if(ch > target) {
                  return ch;
              }
          }
          // wrap around case
          return letters[0];
      }
  };
class Solution {
  public:
      char nextGreatestLetter(vector<char>& letters, char target) {
          int low = 0, high = letters.size() - 1;
      while (low <= high) {
          int mid = low + (high - low)/2;
          if (letters[mid] <= target) low = mid + 1;
          else high = mid - 1;
      }
      return letters[low % letters.size()]; // wrap around
      }
  };

int main(){
  Solution s;
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
    cout << s.nextGreatestLetter(letters, target) << endl;
    
    return 0;
}