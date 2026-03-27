#include<iostream>
#include<vector>
//#include<algorithm> // Included for completeness, though not strictly needed for the functions below

using namespace std;

// Function to find the first occurrence (starting index)
int findone(vector<int>&nums, int target){
  int l = 0, h = nums.size()-1, ans = -1;
  while(l<=h){
    int mid = l + (h-l)/2;
    if(nums[mid]==target){
      ans = mid;
      // Continue searching in the left half for an earlier occurrence
      h = mid -1; 
    }else if(nums[mid]<target){
      l = mid+1;
    }else{
      h = mid-1;
    }
  }
  return ans;
}

// Function to find the last occurrence (ending index)
int findone1(vector<int>&nums, int target){
  int l = 0, h = nums.size()-1, ans = -1;
  while(l<=h){
    int mid = l + (h-l)/2;
    if(nums[mid]==target){
      ans = mid;
      // Continue searching in the right half for a later occurrence
      l = mid +1; 
    }else if(nums[mid]<target){
      l = mid+1;
    }else{
      h = mid-1;
    }
  }
  return ans;
}

// Corrected searchRange function
vector<int> searchRange(vector<int>&nums,int target){
  int first = findone(nums, target);
  int last = findone1(nums, target);
  
  // Return the starting and ending indices
  return {first, last}; 
}

int main(){
  int target;
  cout << "Target value daalein: ";
  cin >> target;

  int n;
  cout << "Vector mein kitne numbers chahiye (n): ";
  cin >> n; // Step 1: Element ki sankhya (n) input lena

  vector<int> nums; // Step 2: Empty vector banaana

  cout << "Ab " << n << " numbers daalein (sorted order mein):" << endl;
  
  // Step 3: Loop chalaakar n elements ko input lena
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    nums.push_back(num); // Element ko vector ke ant mein jodna
  }
  
  // Ab aap searchRange function ko call kar sakte hain
  vector<int> result = searchRange(nums,target);

  cout << "\nResult: [" << result[0] << ", " << result[1] << "]" << endl;

  return 0;
}
