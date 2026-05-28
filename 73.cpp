// https://leetcode.com/problems/merge-intervals/
// https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1

// 1. Brute Force O(N^2)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        vector<vector<int>> ans;
        for(int i = 0; i < arr.size(); i++){
            int s = arr[i][0];
            int e = arr[i][1];

            // step 2
            // skip if merged already by comparing end of next with end of last push interval
            if(!ans.empty() && e <= ans.back()[1]) continue;

            // step 1 
            // update the e by comparing start of next interval
            // if new start is less than the pre end then new end gets updated
            for(int j = i + 1; j < n; j++){
                if(arr[j][0] <= e) e = max(e, arr[j][1]);
                else break;
            }
            ans.push_back({s, e});
        }
        return ans;
    }
};


// 2. Optimal Sol O(N)
// Instead of check for all next element we compare coming element and merge accordingly
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++){
            int s = arr[i][0];
            int e = arr[i][1];
            // update 
            if(!ans.empty() && s <= ans.back()[1]) 
                ans.back()[1] = max(ans.back()[1], e);
            else 
                ans.push_back({s, e});
        }
        return ans;
    }
};