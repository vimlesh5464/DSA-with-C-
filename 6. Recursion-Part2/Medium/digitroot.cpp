#include<iostream>
using namespace std;

int digitRoot(int n){
  if(n < 10)  // ✅ Base case: single digit
    return n;

  int sum = 0;
  while(n > 0){
    sum += n % 10;
    n /= 10;
  }

  return digitRoot(sum);  // ⏎ recursive call
}

int main(){
  cout << digitRoot(9999) << endl;
  return 0;
}
