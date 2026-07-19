// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

class Solution {
  public:
    int findMin(int n) {
        vector<int> coins = {10, 5, 2, 1};
        
        int count = 0;
        
        for(int x : coins){
            while(n >= x){
                n -= x;
                count++;
            }
        }
        return count;
        
    }
};