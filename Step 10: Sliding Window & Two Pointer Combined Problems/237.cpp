// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int n = cardPoints.size();

        if(n == k) 
            return total;

        int windowSize = n - k;
        int ans = 0;
        int windowSum = 0;

        // first window
        for(int i = 0; i < windowSize; i++){
            windowSum += cardPoints[i];
        }
        ans = total - windowSum;

        // rest of the window
        int left = -1;
        for(int i = windowSize; i < n; i++){
            windowSum += cardPoints[i];

            left++;
            windowSum -= cardPoints[left];
            
            ans = max(ans, total - windowSum);
        }

        return ans;

    }
};