#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
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
};

// Driver code for local testing
int main() {
    Solution sol;

    string test1 = "A man, a plan, a canal: Panama";
    string test2 = "race a car";
    string test3 = " ";

    cout << (sol.isPalindrome(test1) ? "true" : "false") << endl; // true
    cout << (sol.isPalindrome(test2) ? "true" : "false") << endl; // false
    cout << (sol.isPalindrome(test3) ? "true" : "false") << endl; // true

    return 0;
}
