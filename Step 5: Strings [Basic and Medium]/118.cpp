// https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        vector<string> bucket(n + 1);
        for (auto& [ch, frq] : freq)
            bucket[frq] += string(frq, ch);

        string ans;
        for (int f = s.size(); f >= 1; --f)
            ans += bucket[f];

        return ans;
    }
};