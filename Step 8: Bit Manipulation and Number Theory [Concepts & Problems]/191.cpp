// https://www.geeksforgeeks.org/problems/find-the-odd-occurence4820/1

class Solution {
  public:
    int getOddOccurrence(vector<int>& arr) {
       int xor_val = 0;
       for(int x : arr) xor_val ^= x;
       return xor_val;
    }
};