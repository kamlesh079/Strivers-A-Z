// https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        int s = 1;
        int e = x;
        int ans = 0;
        while(s <= e){
            long long mid = s + (e - s)/2;
            long long square = mid * mid;
            if (multiple <= x){
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        return ans;
    }
};