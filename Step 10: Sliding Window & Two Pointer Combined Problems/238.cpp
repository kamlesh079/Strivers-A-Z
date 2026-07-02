// https://www.naukri.com/code360/problems/distinct-characters_2221410

#include <unordered_map>

int kDistinctChars(int k, string &str){
    int n = str.size();

    unordered_map<char, int> mp;

    int ans = 0;
    int left = 0;
    
    for(int right = 0; right < n; right++){
        mp[str[right]]++;

        while(mp.size() > k){
            mp[str[left]]--;
            
            if(mp[str[left]] == 0)
                mp.erase(str[left]);
            left++;
        }

        ans = max(ans, right - left + 1);
    }
    return ans;
}