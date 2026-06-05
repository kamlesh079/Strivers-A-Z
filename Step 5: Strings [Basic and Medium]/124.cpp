// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            vector<int> cnt(26, 0);

            for(int j = i ; j < n; j++){
                cnt[s[j] - 'a']++;
                
                int mini = INT_MAX;
                int maxi = INT_MIN;
                for(int x : cnt){
                    if(x > 0){
                        mini = min(mini, x);
                        maxi = max(maxi, x);
                    }
                    
                }
                ans += maxi - mini;
            }
        }
        return ans;
    }
};