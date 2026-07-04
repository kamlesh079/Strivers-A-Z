// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;

        for (char c : t)
            need[c]++;

        int required = need.size();
        int formed = 0;

        int left = 0;

        int start = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];
            window[ch]++;

            if (need.count(ch) && window[ch] == need[ch])
                formed++;

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char remove = s[left];
                window[remove]--;

                if (need.count(remove) && window[remove] < need[remove])
                    formed--;

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};