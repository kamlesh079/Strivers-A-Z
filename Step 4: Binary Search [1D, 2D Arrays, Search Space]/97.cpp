// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    bool isValidCap(int cap, vector<int>& weights, int days){
        int sum = 0;
        int days_taken = 1;
        for(int i = 0; i < weights.size(); i++){
            if(sum + weights[i] > cap){
                days_taken++;
                sum = 0;
            }
            sum += weights[i];
        }
        return days_taken <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = 0;
        int s = *max_element(weights.begin(), weights.end());
        int e = accumulate(weights.begin(), weights.end(), 0);
        while(s <= e){
            int mid = s + (e - s)/2;
            if(isValidCap(mid, weights, days)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};