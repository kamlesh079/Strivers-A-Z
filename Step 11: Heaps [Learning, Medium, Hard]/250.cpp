// https://leetcode.com/problems/rank-transform-of-an-array/
// https://www.naukri.com/code360/problems/replace-each-element-of-array-with-its-corresponding-rank_975384?leftPanelTabValue=PROBLEM



class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rankMap;

        int rank = 1;
        
        for(int x : sorted){
            if(rankMap.find(x) == rankMap.end()){
                // unique;
                rankMap[x] = rank;
                rank++;
            }
        }

        vector<int> ans;
        for(int x : arr){
            ans.push_back(rankMap[x]);
        }
        return ans;
    }
};