// https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;// either use this or put check of sum == k in the loop
                // this make sures the when sum == k
                
        int sum = 0;
        int count = 0;
        for(int x: arr){
            sum += x;
            int target = sum - k;
            if(mp.find(target) != mp.end())
                count += mp[target];
            mp[sum]++;
        }
        return count;
    }
};