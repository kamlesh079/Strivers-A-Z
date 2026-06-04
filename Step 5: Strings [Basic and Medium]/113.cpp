// https://leetcode.com/problems/largest-odd-number-in-string/

class Solution {
public:
    string largestOddNumber(string str) {
        int e = str.size() - 1;
        while(e >= 0){
            int num = str[e] - '0';
            if((num & 1) == 0) 
                e--;
            else 
                break;
        }
        str.resize(e + 1);
        return str;
    }
};