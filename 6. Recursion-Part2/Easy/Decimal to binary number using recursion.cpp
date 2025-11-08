#include <iostream>
#include<string>
using namespace std;

// Decimal to binary conversion
// using recursion
int decToBin(int d)
{
    if (d == 0) 
        return 0; 
    else
        return (d % 2 + 10 * decToBin(d / 2));
}

// Driver code 
int main()
{
    int d = 10;
    cout << decToBin(d);
    return 0;
}



// void decToBinRec(int d, string &res) {
//     if (d > 1) {
//         decToBinRec(d / 2, res);
//     }
//     res += (d % 2) + '0';
// }

// string decToBin(int d) {
//     string res = "";
//     decToBinRec(d, res);
//     return res;
// }

// int main() {
//     int d = 1048576;
//     cout << decToBin(d) << endl;
//     return 0;
// }