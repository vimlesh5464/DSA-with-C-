#  Smallest Prime Multiplier.py - Python skeleton converted from C++

# Original C++ code:
# // Alice is given two integers, ( P ) and ( N ), where ( P ) is a prime number. She needs to find the smallest number ( X ) that is a multiple of both ( P ) and ( N ).
# 
# // Input Format
# 
# // The input consists of two space-separated integers, ( P ) and ( N ).
# 
# // Output Format
# 
# // Return the smallest possible value of ( X ).
# 
# // Constraints
# 
# // 1 <= P, N <= 10^9
# 
# // Sample Testcase 0
# 
# // Testcase Input
# // 3 15
# // Testcase Output
# // 15
# // Explanation
# 
# // We find that 15 is the smallest number, a multiple of 3 and 15.
# // Sample Testcase 1
# 
# // Testcase Input
# // 2 5
# // Testcase Output
# // 10
# // Explanation
# 
# // 10 is the smallest number, a multiple of both 2 and 5.
# 
# #include <iostream>
# using namespace std;
# long long hcf(long long a, long long b) {
#     while(b != 0) {
#         int rem = a % b;
#         a = b;
#         b = rem;
#     }
#     return a;
# }
# long long compute_x(long long p, long long n) {
#     // Write your logic here
#   return (p * n) / hcf(p, n);
# }
# 
# int main() {
#     long long p, n;
#     std::cin >> p >> n;
#     
#     // Call user logic function and print the output
#     long long result = compute_x(p, n);
#     std::cout << result << std::endl;
#     
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
