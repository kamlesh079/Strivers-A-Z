// https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1

class Solution {
  public:
    int xorTillN(int n){
        if(n % 4 == 0) return n;
        else if(n % 4 == 1) return 1;
        else if(n % 4 == 2) return n + 1;
        return 0;
    }
    int findXOR(int l, int r) {
       return xorTillN(r) ^ xorTillN(l - 1);
    }
};