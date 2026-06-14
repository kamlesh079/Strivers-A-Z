// https://www.geeksforgeeks.org/problems/swap-the-numbers/1

// using xor
void swap(int &a, int &b) {
    a = a ^ b; 
    b = a ^ b; // a = a ^ b and b = b => a ^ b ^ b = a
    a = a ^ b; // a = a ^ b and b = a =>  a ^ b ^ a = b
}

// using +, -
void swap(int &a, int &b) {
    a = a + b;
    b = a - b; // a = a + b, b = b  => a + b - b = a;
    a = a - b; // a = a + b, b = a  => a + b - a = b;
}