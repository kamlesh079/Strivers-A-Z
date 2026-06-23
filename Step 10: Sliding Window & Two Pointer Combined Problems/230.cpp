// https://leetcode.com/problems/longest-substring-without-repeating-characters

// Map solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int start = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >= start){
                start = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};

// Using vector instead of unordered_map for better performance since the character set is limited to 256 ASCII characters.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256, -1);
        int start = 0;
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            if(mp[s[i]] != -1 && mp[s[i]] >= start){
                start = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};