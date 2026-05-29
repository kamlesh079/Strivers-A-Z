// # Sum of first N numbers

#include <iostream>
using namespace std;

int sumToN(int n){
    // base case
    if(n == 0) return 0;

    int sum = 0;
    sum = n + sumToN(n - 1);
    // recursive case
   
    return sum;
}

int main(){
    int n = 0;
    cin >> n;
    cout << sumToN(n) << endl; 
    return 0;
}