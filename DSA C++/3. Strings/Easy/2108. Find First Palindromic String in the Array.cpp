// Ronak, a young wizard with the power to identify palindromic words, was exploring an array of strgin A of length N filled with ancient strings. He decided to find the first palindromic string from the array using his abilities.

// Note: strgin in array A consist of onyl lowercase English alphabets.

// Input Format

// The first line contains an integer N that will be passed,, representing the size of the array A.

// The next line contains N strings separated by spaces for arrray A.

// Output Format

// Print the first palindromic string in the array. If there is no such string, return an empty string "".

// Constraints

// 1 <= N <= 10^5


// 1 <= A[i]<= 10^2

// Sample Testcase 0

// Testcase Input
// 5
// hello world level algorithm madam
// Testcase Output
// level
// Explanation

// The first palindromic word in the given list is "level" because it reads the same forward and backward.
// Sample Testcase 1

// Testcase Input
// 4
// hello world python programming
// Testcase Output
// Explanation

// There are no palindromic words in the given list, so the function returns an empty string ("").

#include <iostream>
#include <vector>
#include <string>
using namespace std;
string firstPalindrome(vector<string>& words) {
  for (const string& word : words) {
  string rev = word;        // Make a copy
  reverse(rev.begin(), rev.end()); // Reverse the copy
  if (word == rev) {        // Check if palindrome
      return word;          // Return immediately
  }
}
return ""; // No palindrome found
}
bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            // Compare lowercase characters
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
// Placeholder function for user logic
string firstPalindrome(const vector<string>& words) {
    // User should implement the logic here
    // This function should return the first palindromic string in the array
    // If no such string exists, return an empty string ""
   if(words.size() <= 0){
    return "";
   }
    for(int i = 0; i < words.size(); i++){
        string word = words[i];
        bool bl = isPalindrome(word);
        if(bl == true){
            return word;
        }
    }
    
    return "";
}

int main() {
    int n;
    cin >> n; // Read the number of strings
    
    if (n <= 0) { // Edge case: No strings provided
        cout << "" << endl;
        return 0;
    }
    
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // Read each string into the array
    }
    
    // Call user logic function and print the output
    string result = firstPalindrome(arr);
    cout << result << endl;
    
    return 0;
}
