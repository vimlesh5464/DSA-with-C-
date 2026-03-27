#include<iostream>
using namespace std;
// tower of honoi
void towerOfHanoi(int n, char A, char B, char C) {
    if(n == 1) {
        cout << "Move disk 1 from " << A << " to " << C << endl;
        return;
    }
    towerOfHanoi(n - 1, A, C, B); // Move n-1 disks from A to B using C
    cout << "Move disk " << n << " from " << A << " to " << C << endl;
    towerOfHanoi(n - 1, B, A, C); // Move n-1 disks from B to C using A
}

int main() {
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
