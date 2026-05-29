// # Understand recursion by print something N times

#include <iostream>
using namespace std;

void print(int n){
    if(n == 0) return;
    
    print(n - 1);
    cout << n << " ";
}

int main(){
    int n = 0;
    cin >> n;
    print(n);
    cout << endl;
 
    return 0;
}