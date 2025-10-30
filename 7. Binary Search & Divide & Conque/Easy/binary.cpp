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
      return i;
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
  vector<int> arr = {1,2,3,4,5};
  cout<< binary(arr,5);
  return 0;
}