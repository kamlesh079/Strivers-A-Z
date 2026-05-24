// # Print name N times using recursion

#include <iostream>
#include <string>
using namespace std;

void printName(string str, int n){
    if( n == 0) return;
    printName(str, n - 1);
    cout << n << " "<< str << endl;
}

int main(){
    int n = 0;
    cin >> n;
    printName("kamlesh", n);
 
    return 0;
}