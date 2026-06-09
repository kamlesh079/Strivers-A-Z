// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int solve(string &s, int i, long long ans, int sign){
        int n = s.size();

        if (i >= n || !isdigit(s[i]))
            return sign * ans;
        
        int digit = s[i] - '0';

        ans = ans * 10 + digit;

        if (ans * sign > INT_MAX)
            return INT_MAX;

        if (ans * sign < INT_MIN)
            return INT_MIN;
        
        return solve(s, i + 1, ans, sign);
    }

    int skipSpaces(string& s, int i){
        if( i >= s.size() || s[i] != ' ') return i;
        return skipSpaces(s, i + 1);
    }
    int myAtoi(string s) {
        // skip spaces using recursion
        int i = skipSpaces(s, 0);

        // cal sign
        int sign = 1;
        if(i < s.size() && s[i] == '-' || s[i] == '+'){
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }

        // parse the rest of the things
        return solve(s, i, 0, sign); // (string, index, ans, sign)
    }
};