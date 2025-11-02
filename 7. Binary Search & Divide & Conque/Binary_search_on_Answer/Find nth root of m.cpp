#include<iostream>
#include <cmath>
using namespace std;
int nThroot(int n, int m){
  for(int i = 1; i <= m; i++){
    long long power = pow(i,n);
    if(power==m){
      return i;
    }
    if(power>m){
      break;
    }
  }
  return -1;
}

int nThroot1(int n, int m){
  int l = 1, h = m;
  while(l<=h){
    int mid = (l+h)/2;
    if(pow(mid,n)==m){
      return mid;
    }else if(pow(mid,n)<m){
      l = mid+1;
    }else{
      h=mid-1;
    }
  }
  return -1;
}

int main(){
  int n, m;
  cin>>n>>m;
  cout<<nThroot1(n,m);
  return 0;
}