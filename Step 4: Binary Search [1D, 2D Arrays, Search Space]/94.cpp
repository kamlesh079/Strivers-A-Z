// https://leetcode.com/problems/koko-eating-bananas/
// https://www.geeksforgeeks.org/dsa/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;

        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        while (s <= e) {
            int mid = s + (e - s) / 2;
            long long totalHr = 0;
            for (int x : piles)
                totalHr += ceil((double)x / mid); // don't forget to covert to double
            if (totalHr <= h) {
                ans = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }
        return ans;
    }
};