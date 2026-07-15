https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1

class Solution{
public:
    string minWindow(string &s1, string &s2){
        int n = s1.size();
        int m = s2.size();

        int bestStart = -1;
        int bestLen = INT_MAX;

        int i = 0;
        while (i < n){
            // forward scan
            int j = 0;
            while (i < n){
                if (s1[i] == s2[j])
                    j++;
                if (j == m)
                    break;
                i++;
            }
            if (i == n)
                break;

            // backward scan to get bestStart
            int end = i;
            j = m - 1; // may be j is at m from pre while loop that is why j = m - 1
            while (j >= 0){
                if (s1[i] == s2[j])
                    j--;
                i--;
            }

            i++; //  bestStart

            if (end - i + 1 < bestLen){
                bestLen = end - i + 1;
                bestStart = i;
            }

            // continue from next index
            i++;
        }
        if (bestStart == -1)
            return "";
        return s1.substr(bestStart, bestLen);
    }
};
