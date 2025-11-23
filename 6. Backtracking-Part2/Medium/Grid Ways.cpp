#include <iostream>
using namespace std;
////solution 1
int gridWays(int i, int j, int n, int m) {
    // Base Case: reached bottom-right
    if (i == n - 1 && j == m - 1) return 1;

    // Boundary Case: out of grid
    if (i >= n || j >= m) return 0;

    // Move Down + Move Right
    return gridWays(i + 1, j, n, m) + gridWays(i, j + 1, n, m);
}

//solution 2
int factorial(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++)
      res *= i;
  return res;
}

int gridWays(int n, int m) {
  int num = factorial(n + m - 2);
  int den = factorial(n - 1) * factorial(m - 1);
  return num / den;
}
int main() {
    int n = 3, m = 3;
    cout << gridWays(0, 0, n, m);
    return 0;
}
