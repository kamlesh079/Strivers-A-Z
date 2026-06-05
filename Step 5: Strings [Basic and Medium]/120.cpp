// # Roman to Integer -> https://leetcode.com/problems/roman-to-integer/description/

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int sum = 0;
        for(int i = n - 1; i >= 0; i--){
            if(i + 1 < n && mp[s[i]] < mp[s[i + 1]])
                sum -= mp[s[i]];
            else 
                sum += mp[s[i]];
        }
        return sum;
    }
};


//# Integer to Roman -> https://leetcode.com/problems/integer-to-roman/description/

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = {
            {1000, "M"}, 
            {900, "CM"}, 
            {500, "D"}, 
            {400, "CD"}, 
            {100, "C"},
            {90, "XC"},  
            {50, "L"},   
            {40, "XL"}, 
            {10, "X"},   
            {9, "IX"},
            {5, "V"},    
            {4, "IV"},   
            {1, "I"}};
        
        string ans = "";
        for(auto&[val, sym] : roman){
            while(num >= val){
                ans += sym;
                num -= val;
            }
        }
        return ans;
    }
};