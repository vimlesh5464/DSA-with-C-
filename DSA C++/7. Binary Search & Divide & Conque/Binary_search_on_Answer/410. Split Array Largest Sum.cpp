//Allocate book or  Painter's Partition or Split Array Largest Sum are same problem
#include<iostream>
#include<vector>
#include <numeric>  
using namespace std;

// Count how many students are required if each student can read at most 'pages' pages
int countStudents(vector<int> &arr, long long pages) {
    int students = 1;
    long long pagesStudent = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        } else {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

// Find the minimum possible maximum pages allocation
int findPages(vector<int> &arr, int n, int m) {
    if (m > n) return -1; // More students than books → impossible

    int low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0LL);
    int ans = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        int students = countStudents(arr, mid);

        if (students > m) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

// Wrapper function (as in the original snippet)
int findLargestMinDistance(vector<int> &arr, int k) {
    return findPages(arr, arr.size(), k);
}

int main() {
    int n, m;
    cout << "Enter number of books: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter number of pages in each book: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter number of students: ";
    cin >> m;

    cout << "\nMinimum possible maximum pages = "
         << findLargestMinDistance(arr, m) << endl;

    return 0;
}
