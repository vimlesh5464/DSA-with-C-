// Postfix Evaluation
// Difficulty: MediumAccuracy: 63.04%Submissions: 127K+Points: 4

// You are given an array of strings arr[] that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

// Note: A postfix expression is of the form operand1 operand2 operator (e.g., "a b +"). 
// And the division operation between two integers always computes the floor value, i.e floor(5 / 3) = 1 and floor(-5 / 3) = -2.
// It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit signed integer.

// Examples:

// Input: arr[] = ["2", "3", "1", "*", "+", "9", "-"]
// Output: -4
// Explanation: If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.

// Input: arr[] = ["2", "3", "^", "1", "+"]
// Output: 9
// Explanation: If the expression is converted into an infix expression, it will be 2 ^ 3 + 1 = 8 + 1 = 9.

// Constraints:
// 3 ≤ arr.size() ≤ 103
// arr[i] is either an operator: "+", "-", "*", "/" or "^", or an integer in the range [-104, 104]


#include <iostream>
#include <cmath>     
#include<string>
#include<vector>
#include<stack>
using namespace std;


class Solution {
public:
    // Function to evaluate postfix expression
    int evaluatePostfix(vector<string>& arr) {
        stack<long long> st;
        
        for (string &token : arr) {
            // If token is a number (handles negative numbers too)
            if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
                st.push(stoll(token));
            } else {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(floorDiv(a, b));
                else if (token == "^") st.push(pow(a, b));
            }
        }
        return (int)st.top();
    }

private:
    // Custom floor division to handle negative numbers
    long long floorDiv(long long a, long long b) {
        long long res = a / b;
        if ((a ^ b) < 0 && a % b != 0) res--; // adjust for negatives
        return res;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<string> expr1 = {"2", "3", "1", "*", "+", "9", "-"};
    cout << "Postfix evaluation result: " << sol.evaluatePostfix(expr1) << endl;
    // Output: -4

    // Example 2
    vector<string> expr2 = {"4", "13", "5", "/", "+"};
    cout << "Postfix evaluation result: " << sol.evaluatePostfix(expr2) << endl;
    // Output: 6 (4 + 13/5)

    return 0;
}

