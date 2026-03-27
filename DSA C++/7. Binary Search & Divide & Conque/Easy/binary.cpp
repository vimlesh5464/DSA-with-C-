#include<iostream>
#include<vector>
using namespace std;
int binary(vector<int> & arr, int target){
  int n = arr.size();
  int i = 0;
  int j = n-1;
  while(i<=j){
    int mid = (i+j)/2;
    if(arr[mid]==target){
      return mid;
    }
    else if(arr[mid]<target){
      i = mid +1;
    }else{
      j = mid-1;
    }
  }
  return -1;
}
int main(){
  int n;
  cin>>n;
  int target;
  cin>> target;
  vector<int> arr(n);
for(int i = 0; i < n; i++){
    cin >> arr[i];
}


  cout<< binary(arr,target);
  return 0;
}