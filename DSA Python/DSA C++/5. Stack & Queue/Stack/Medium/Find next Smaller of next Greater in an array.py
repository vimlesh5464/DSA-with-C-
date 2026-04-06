# Find next Smaller of next Greater in an array.py - Python skeleton converted from C++

# Original C++ code:
# // Given an array arr[] of integers, find the next smaller element of the next greater 
# //element for each element in the array.
# 
# // Note: Elements for which no greater element exists or no smaller of greater element exist,
# // print -1.
# 
# // Examples: 
# 
# //     Input : arr[] = [5, 1, 9, 2, 5, 1, 7]
# //     Output:  [2, 2, -1, 1, -1, -1, -1]
# //     Explanation:
# //     420851503
#      
# 
# //     Input  : arr[] = [4, 8, 2, 1, 9, 5, 6, 3]
# //     Output :  [2,  5,  5,  5, -1,  3, -1, -1]      
# #include<iostream>
# #include<vector>
# #include<stack>
# using namespace std;
# 
# // Time Complexity of this solution is O(n2).
# 
# // Space Complexity: O(1) 
# 
# // Function to find Right smaller element of next greater
# // element
# void nextSmallerOfNextGreater(int arr[], int n)
# {
#     vector<int> vec;
#     //For 1st n-1 elements of vector
#     for(int i=0;i<n-1;i++){
#        
#         int temp=arr[i];
#         int next=-1;
#         int ans=-1;
#         for(int j=i+1;j<n;j++){
#           if(arr[j]>temp){
#               next=j;
#               break;
#           } 
#         }
#          
#         if(next==-1){vec.push_back(-1);}
#         else{
#           for(int j=next+1;j<n;j++){
#               if(arr[j]<arr[next]){
#                   ans=j;
#                   break;
#               } 
#           }
#           if(ans==-1){vec.push_back(-1);}
#           else{vec.push_back(arr[ans]);}
#         }
#         
#     }
#     
#     vec.push_back(-1);//For last element of vector
#     for(auto x: vec){
#         cout<<x<<" ";
#     }
#     cout<<endl;
# }
# 
# 
# // Time complexity : O(n), where n is the size of the given array.
# // Auxiliary Space: O(n), where n is the size of the given array.
# // function find Next greater element
# void nextGreater(int arr[], int n, int next[], char order)
# {
#     // create empty stack
#     stack<int> S;
# 
#     // Traverse all array elements in reverse order
#     // order == 'G' we compute next greater elements of
#     //              every element
#     // order == 'S' we compute right smaller element of
#     //              every element
#     for (int i=n-1; i>=0; i--)
#     {
#         // Keep removing top element from S while the top
#         // element is smaller than or equal to arr[i] (if Key is G)
#         // element is greater than or equal to arr[i] (if order is S)
#         while (!S.empty() &&
#               ((order=='G')? arr[S.top()] <= arr[i]:
#                            arr[S.top()] >= arr[i]))
#             S.pop();
# 
#         // store the next greater element of current element
#         if (!S.empty())
#             next[i] = S.top();
# 
#         // If all elements in S were smaller than arr[i]
#         else
#             next[i] = -1;
# 
#         // Push this element
#         S.push(i);
#     }
# }
# 
# // Function to find Right smaller element of next greater
# // element
# void nextSmallerOfNextGreater(int arr[], int n)
# {
#     int NG[n]; // stores indexes of next greater elements
#     int RS[n]; // stores indexes of right smaller elements
# 
#     // Find next greater element
#     // Here G indicate next greater element
#     nextGreater(arr, n, NG, 'G');
# 
#     // Find right smaller element
#     // using same function nextGreater()
#     // Here S indicate right smaller elements
#     nextGreater(arr, n, RS, 'S');
# 
#     // If NG[i] == -1 then there is no smaller element
#     // on right side. We can find Right smaller of next
#     // greater by arr[RS[NG[i]]]
#     for (int i=0; i< n; i++)
#     {
#         if (NG[i] != -1 && RS[NG[i]] != -1)
#             cout << arr[RS[NG[i]]] << " ";
#         else
#             cout<<"-1"<<" ";
#     }
# }
# // Driver program
# int main()
# {
#     int arr[] = {5, 1, 9, 2, 5, 1, 7};
#     int n = sizeof(arr)/sizeof(arr[0]);
#     nextSmallerOfNextGreater(arr, n);
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
