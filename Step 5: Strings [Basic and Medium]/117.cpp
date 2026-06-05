// https://leetcode.com/problems/valid-anagram/


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        vector<int> frq(26, 0);

        for (int i = 0; i < s.size(); i++) {
            frq[s[i] - 'a']++;
            frq[t[i] - 'a']--;
        }
        for (int x : frq)
            if (x != 0)
                return false;
        return true;
    }
};


// Early Exit (Better) 
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    int freq[26] = {};

    for (char c : s)
        freq[c - 'a']++;

    for (char c : t)
        if (--freq[c - 'a'] < 0)
            return false;

    return true;
}