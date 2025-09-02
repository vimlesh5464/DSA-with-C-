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
