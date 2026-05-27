// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// Pattern -> this problem is same as subarray with sum = k, here k = 0

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int prefixSum = 0;
        int maxlen = 0;
        
        for(int i = 0; i < arr.size(); i++){
            prefixSum += arr[i];
            // target = prefixSum - 0 = prefixSum;
            if(mp.find(prefixSum) != mp.end()){
                maxlen = max(maxlen, i - mp[prefixSum]);
            }
            if(mp.find(prefixSum) == mp.end())  // to maximize the subarray len
                mp[prefixSum] = i;
        }
        return maxlen;
        
    }
};