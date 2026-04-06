#  Reduced Zero.py - Python skeleton converted from C++

# Original C++ code:
# // You have to make a given integer N to zero.
# 
# // You can subtract the smallest prime factor of N and subtract it from N and stop when N becomes zero.
# 
# // Return the number of times you have applied the operations.
# 
# // Input Format
# 
# // The line contains a single Integer representing N.
# 
# // Output Format
# 
# // A single integer representing a number of operations you have performed.
# 
# // Constraints
# 
# // 2 <= N <= 10^9, where N is the entered integer.
# 
# // Sample Testcase 0
# 
# // Testcase Input
# // 4
# // Testcase Output
# // 2
# // Explanation
# 
# // 2 is the smallest prime divisor of 4, 4-2 = 2
# // Again, 2 is the smallest prime divisor of 2; therefore 2-2 = 0. We stop as N becomes zero.
# // So, our answer is 2.
# // Sample Testcase 1
# 
# // Testcase Input
# // 7
# // Testcase Output
# // 1
# // Explanation
# 
# // 7 is the smallest prime divisor. Thus it gets subtracted right away to make a 0.
# 
# 
# #include <iostream>
# using namespace std;
# 
# // Function to be implemented by the user
# int prime(int n) {
#     if (n %2 ==0) return 2; // 0 and 1 are not prime
#     for (int i = 3; i <= sqrt(n); i = i +2) {
#         if (n % i == 0) return i; // divisible
#     }
#     return n; // no divisors found
# }
# int user_logic(int n) {
#     if(n%2==0){
#         return n/2;
#     }
# 
#     int spf = prime(n);
#     int operations = 1;
#     n = n - spf;
#     operations += n / 2;
#     return operations;
# }
# 
# int main() {
#     int n;
#     cin >> n;
# 
#     // Call user logic function and print the output
#     int result = user_logic(n);
#     cout << result << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
