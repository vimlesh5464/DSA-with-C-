

#include <iostream>
#include <stack>
#include <vector>
#include <sstream> 
using namespace std;
// [Expected Approach] Stack-Based Word Reversal - O(n) Time and O(n) Space

//     We use a stack to store words character by character until we encounter
//      a space. When a space is found, we pop and print the characters from the stack,
//       effectively reversing the word. This process continues for all words in the string

string reverseWords(string str) {
    stack<char> st;
    string result = "";

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != ' ') {
            st.push(str[i]);
        } else {
            while (!st.empty()) {
                result += st.top();
                st.pop();
            }
            result += " "; // Add space after the word
        }
    }

    // Reverse the last word (since it may not end with a space)
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

//[Alternate Approach] Using Inbulit Functions - O(n) Time and O(n) Space
string reverseWords(string str)
{
    // word variable to store word
    string word;

    // making a string stream
    stringstream iss(str);

    // Read and print each word.
    string s1 = "";
    while (iss >> word) {
        reverse(word.begin(), word.end());
        s1 += word;
        s1 += " ";
    }
    return s1;
}


// Driver program to test function
int main() {
    string str = "Geeks for Geeks";
    string reversedString = reverseWords(str);
    cout << reversedString << endl;
    return 0;
}