// # Print N to 1 using recursion

#include <iostream>
using namespace std;

void print(int n){
    if(n == 0) return;
    cout << n << " ";
    print(n - 1);
}

int main(){
    int n = 0;
    cin >> n;
    print(n);
    cout << endl;
 
    return 0;
}