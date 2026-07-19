// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

        unordered_map<int, int> mp;
        for(int x : nums)
            mp[x]++;

        for(auto it : mp){
            minheap.push({it.second, it.first});
            if(minheap.size() > k) minheap.pop();
        }

        vector<int> ans;

        while(!minheap.empty()){
            auto [freq, num] = minheap.top();
            minheap.pop();
            ans.push_back(num);
        }
        return ans;
    }
};