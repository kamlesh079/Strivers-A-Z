// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

// Method 1: Sliding Window
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> frq(3,0);

        int count = 0;
        int n = s.size();
        int left = 0;

        for(int right = 0; right < n; right++){
            frq[s[right] - 'a']++;
            
            while(frq[0] > 0 && frq[1] > 0 && frq[2] > 0){
                count += n - right;
                frq[s[left] - 'a']--;
                left++;
            }
        }
        return count;
    }
};

// Method 2: using atMost function
class Solution {
public:
    int atMost(string& s, int k) {
        unordered_map<char, int> mp;

        int left = 0;
        int count = 0;

        for (int right = 0; right < s.size(); right++) {

            mp[s[right]]++;

            while (mp.size() > k) {
                
                mp[s[left]]--;

                if (mp[s[left]] == 0)
                    mp.erase(s[left]);

                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
    int numberOfSubstrings(string s) {
        long long n = s.size();
        long long total = n * (n + 1) / 2;
 
        return total - atMost(s, 2);
    }
};