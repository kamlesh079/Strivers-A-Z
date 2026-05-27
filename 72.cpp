// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

// Pattern - same as subarray with sum = k

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; // handles subarrays starting from index 0
        
        int prefixXor = 0;
        int count = 0;
        for(int x: arr){
            prefixXor ^= x;
            int req = prefixXor ^ k;
            if(mp.find(req) != mp.end())
                count += mp[req];
            mp[prefixXor]++;
        }
        return count;
    }
};