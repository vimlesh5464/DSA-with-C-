#include<iostream>
using namespace std;
int sqrt(int x){
  long long l = 0, h = x, ans = 0;
  while(l<=h){
    long long mid = l + (h-l)/2;
    if(mid*mid<=x){
      ans = mid;
      l = mid +1;
    }else{
      h = mid-1;
    }
  }
  return ans;
}

int main(){
  int x;
  cin>> x;
  cout<< sqrt(5);
  return 0;
}