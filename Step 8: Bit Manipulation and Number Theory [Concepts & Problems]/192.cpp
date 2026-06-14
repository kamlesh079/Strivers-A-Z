// https://www.geeksforgeeks.org/problems/power-set4302/1

class Solution {
  public:
    // Power set using Bit Manipulations
    vector<string> powerSet(string &s) {
        vector<string> ans;
        int n = s.size();
        int total = 1 << n;
        
        for(int mask = 0; mask < total; mask++){
            string str = "";
            for(int i = 0; i < s.size(); i++){
                if(mask & (1 << i))
                    str.push_back(s[i]);
            }   
            ans.push_back(str);
        }
        sort(ans.begin(), ans.end());
        return ans;   
    }
};