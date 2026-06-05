// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    int expandAround(int l, int r, string& s){
        int n = s.size();
        while(l >= 0 && r < n && s[l] == s[r]){
            r++;
            l--;
        }
        // both are at wrong index where 'while' breaks(false)
        return r - l - 1;
    }
    string longestPalindrome(string s) {
        int n = s.size();

        int sId = 0;
        int eId = 0;
        
        for(int i = 0; i < n; i++){
            int len1 = expandAround(i, i , s);
            int len2 = expandAround(i, i + 1, s);
            
            int maxLen = max(len1, len2);

            if(maxLen > eId - sId + 1){
                sId = i - (maxLen - 1) /2; // imp
                eId= i + (maxLen / 2);
            }
        }
        return s.substr(sId, eId - sId + 1);
    }
};