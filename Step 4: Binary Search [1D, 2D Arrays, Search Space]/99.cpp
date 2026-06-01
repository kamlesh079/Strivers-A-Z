// https://www.geeksforgeeks.org/problems/aggressive-cows/1 
// https://www.spoj.com/problems/AGGRCOW/

class Solution {
  public:
    bool isValid(int dist, vector<int> &stalls, int k){
        int n = stalls.size();
        
        int count = 1;// at pos stalls[0];
        int lastPos = stalls[0]; // to keep track where last cow placed
        for(int i = 1; i < n; i++){
            if(lastPos + dist <= stalls[i]){ // we need to check from last placed not prev stall (i - 1)
                count++;
                lastPos = stalls[i];
                if(count >= k) return true; // early exit
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        int ans = 0;
        
        if(n < k) return ans; // not possible as no of stalls is less than no of cows
        
        sort(stalls.begin(), stalls.end());
        
        int s = 1;;
        int e = stalls[n-1] - stalls[0]; // this is max possible dis b/w two stalls
        while(s <= e){
            int mid = s + (e - s)/2;
            if(isValid(mid, stalls, k)){
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        return ans;
        
    }
};