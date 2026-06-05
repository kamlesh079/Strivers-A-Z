// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();

        int i = 0;
        // skip leadin spaces
        while (i < n && s[i] == ' ')
            i++;

        // sign calculation
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        // process digits(if leading are zero it will be handled automatically)
        // or u can do manually 
        // while(i < n && s[i] == '0') i++;

        long long ans = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            ans = ans * 10 + digit;

            if (ans * sign > INT_MAX)
                return INT_MAX;
            if (ans * sign < INT_MIN)
                return INT_MIN;
            i++;
        }
        return sign * ans;
    }
};