//  https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// # Note: This Map method may give TLE
// Function to count substrings with at most k distinct characters
int atMostKDistinct(string s, int k) {
    // Left pointer and result
    int left = 0;
    int res = 0;
    // Frequency map
    unordered_map<char, int> freq;

    // Iterate through string with right pointer
    for (int right = 0; right < s.size(); right++) {
        // Add current character
        freq[s[right]]++;

        // Shrink window if distinct characters exceed k
        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }

        // Count substrings in current window
        res += (right - left + 1);
    }
    return res;
}

// TLE Free Using Vector to avoid map overhead
class Solution {
public:
    int atMostKDistinct(string &s, int k) {
        vector<int> freq(26, 0);

        int left = 0;
        int distinct = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            if (freq[s[right] - 'a'] == 0)
                distinct++;

            freq[s[right] - 'a']++;

            while (distinct > k) {
                freq[s[left] - 'a']--;

                if (freq[s[left] - 'a'] == 0)
                    distinct--;

                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

    int countSubstr(string &s, int k) {
        return atMostKDistinct(s, k) -
               atMostKDistinct(s, k - 1);
    }
};

// Function to count substrings with exactly k distinct characters
int countSubstrings(string s, int k) {
    // Exactly k = atMost(k) - atMost(k-1)
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main() {
    // Sample test
    string s = "pqpqs";
    int k = 2;

    // Output the result
    cout << "Count: " << countSubstrings(s, k) << endl; // Output: 7
    return 0;
}