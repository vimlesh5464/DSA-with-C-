//Maximum product of a triplet (subsequence of size 3) in array
// A C++ program to find a maximum product of a
// triplet in array of integers using nestd loops
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//[Naive Approach] By Using three nested loops 
// Time Complexity: O(n3)
// Auxiliary Space: O(1)

// Function to find a maximum product of a triplet
//   in array of integers of size n
int maxProduct(vector<int> arr)
{
    int n = arr.size();

    int maxProduct = -1e9;

    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                maxProduct = max(maxProduct, arr[i] * arr[j] * arr[k]);

    return maxProduct;
}

//[Better Approach] By Using sorting - Time O(n*log(n)) and Space O(1)

int maxProduct(vector<int>arr)
{
    int n=arr.size();
    
    // Sort the array in ascending order
    sort(arr.begin(), arr.end());

    // Return the maximum of product of last three
    // elements and product of first two elements
    // and last element
    return max(arr[0] * arr[1] * arr[n - 1],
    arr[n - 1] * arr[n - 2] * arr[n - 3]);
}

//[Expected Approach] By Using Greedy approach - Time O(n) and Space O(1) 

int maxProduct1(vector<int> &arr)
{
    int n = arr.size();
    
    // Initialize Maximum, second maximum and third
    // maximum element
    int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN;

    // Initialize Minimum and second minimum element
    int minA = INT_MAX, minB = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        // Update Maximum, second maximum and third maximum element
        if (arr[i] > maxA)
        {
            maxC = maxB;
            maxB = maxA;
            maxA = arr[i];
        }
        // Update second maximum and third maximum element
        else if (arr[i] > maxB)
        {
            maxC = maxB;
            maxB = arr[i];
        }
        // Update third maximum element
        else if (arr[i] > maxC)
            maxC = arr[i];

        // Update Minimum and second minimum element
        if (arr[i] < minA)
        {
            minB = minA;
            minA = arr[i];
        }
        // Update second minimum element
        else if (arr[i] < minB)
            minB = arr[i];
    }

    return max(minA * minB * maxA, maxA * maxB * maxC);
}

int main()
{
    vector<int>arr = {-10, -3, 5, 6, -20};

    cout<<maxProduct(arr)<<endl;
    
    return 0;
}