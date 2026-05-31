// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

class Solution {
public:
    bool validDay(vector<int>& bloomDay, int mid, int m, int k){
        int n = bloomDay.size();
        
        int count = 0;
        for(int i = 0 ; i < n; i++ ){
            if(bloomDay[i] <= mid){
                count++;
            }
            else count = 0;

            if ( count == k){
                m--;
                count = 0;
                if ( m == 0) break;
            }
        }
        return  m == 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long req = (long long)m * (long long)k;
        if ( req > n) return -1;
        int s = * min_element(bloomDay.begin(), bloomDay.end());
        int e = * max_element(bloomDay.begin(), bloomDay.end());
        int ans = 0;
        while ( s <= e){
            int mid = s + ( e - s)/2;
            if (validDay(bloomDay,mid, m, k)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};