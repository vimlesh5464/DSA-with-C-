# 278. First Bad Version.py - Python skeleton converted from C++

# Original C++ code:
# #include<iostream>
# using namespace std;
# int firstBadVersion(int n) {
#   int l = 1, h = n, ans = n;
#   while(l<=h){
#       int mid = l + (h - l) / 2;
#       if(isBadVersion(mid)){
#           ans=mid;
#           h = mid-1;
#       }else{
#           l = mid+1;
#       }
#   }
#   return ans;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
