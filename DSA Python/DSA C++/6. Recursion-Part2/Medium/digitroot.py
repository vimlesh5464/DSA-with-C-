# digitroot.py - Python skeleton converted from C++

# Original C++ code:
# #include<iostream>
# using namespace std;
# 
# int digitRoot(int n){
#   if(n < 10)  // ✅ Base case: single digit
#     return n;
# 
#   int sum = 0;
#   while(n > 0){
#     sum += n % 10;
#     n /= 10;
#   }
# 
#   return digitRoot(sum);  // ⏎ recursive call
# }
# 
# int main(){
#   cout << digitRoot(9999) << endl;
#   return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
