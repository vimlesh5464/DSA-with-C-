#include<iostream>
using namespace std;
bool valid_perfect_square(int n){
  int l = 0, h = n;
  while(l<=h){
    int mid = l + (h-l)/2;
    if(mid*mid==n){
      return true;
    }else if(mid*mid<n){
      l = mid+1;
    }else{
      h = mid-1;
    }
  }
  return false;
}

int main(){
  int n;
  cin>> n;
  cout<<valid_perfect_square(n);
  return 0;
}