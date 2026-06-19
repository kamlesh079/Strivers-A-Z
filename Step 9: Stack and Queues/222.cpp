// https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        // stack<char> st;
        string str = "";
        for (char ch : num) {
            while (!str.empty() && k > 0 && str.back() > ch) {
                str.pop_back();
                k--;
            }
            // st.push(ch);
            str.push_back(ch);
        }

        // if still k > 0
        while (!str.empty() && k > 0) {
            str.pop_back();
            // st.push(ch);
            k--;
        }

        // remove leading zeros
        int i = 0;
        while (i < str.size() && str[i] == '0')
            i++;
        
        string ans = str.substr(i);
        
        return ans.empty() ? "0" : ans;
    }
};