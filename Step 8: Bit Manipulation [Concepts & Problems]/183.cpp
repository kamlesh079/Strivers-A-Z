// https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

// lets suppuse the the n is  1|0|0|0|0|0|0|0 
// and n - 1 will be          0|x|x|x|x|x|x|x         x -> can be either 0, 1
//                          & _______________
//                         => 0|0|0|0|0|0|0|0      

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        return (1 << k) & n;
    }
};