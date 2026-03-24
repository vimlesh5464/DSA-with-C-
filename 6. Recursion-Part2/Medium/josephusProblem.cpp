// There are n people standing in a circle, numbered from 1 to n. Starting from person 1, counting proceeds in clockwise direction. In each step, exactly k-1 people are skipped, and the k-th person is eliminated from the circle. The counting then resumes from the next person, and the process continues until only one person remains.

// Determine the position of the last surviving person in the original circle.

// Examples:

//     Input: n = 5, k = 2
//     Output: 3
//     Explanation: Firstly, the person at position 2 is killed, then the person at position 4 is killed, then the person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives. 

//     Input: n = 7, k = 3
//     Output: 4
//     Explanation: The persons at positions 3, 6, 2, 7, 5, and 1 are killed in order, and the person at position 4 survives.
#include<iostream>
using namespace std;
//josephusProblem
int josephusProblem(int n, int k){// o(n)
    if(n == 1){
        return 0;
    }
    return (josephusProblem(n - 1, k) + k) % n;
}

int main(){
    int n = 5, k = 3;
    cout << "Safe position: " << josephusProblem(n, k) << endl;
    return 0;
}
