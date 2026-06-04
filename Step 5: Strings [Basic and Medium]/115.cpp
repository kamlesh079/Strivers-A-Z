// https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> st;
        unordered_map<char, char> ts;
        for (int i = 0; i < s.size(); i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            if ((st.count(ch1) && st[ch1] != ch2) ||
                (ts.count(ch2) && ts[ch2] != ch1))
                return false;

            st[ch1] = ch2;
            ts[ch2] = ch1;
        }
        return true;
    }
};