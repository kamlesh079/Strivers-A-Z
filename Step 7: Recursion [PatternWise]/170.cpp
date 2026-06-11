// https://www.geeksforgeeks.org/problems/subset-sums2234/1


class Solution {
  public:
    void solve(int id, vector<int>& arr, int sum, vector<int>& ans){
        if(id == arr.size()){
            ans.push_back(sum);
            return;
        }
        // include
        solve(id + 1, arr, sum + arr[id], ans);
        // exclude
        solve(id + 1, arr, sum, ans);
    }
    
    void solve(int id, vector<int>& arr, int sum, vector<int>& ans){
        ans.push_back(sum);
        
        for(int i = id; i < arr.size(); i++){
            solve(i + 1, arr, sum + arr[i], ans);
        }
        
    }
    vector<int> subsetSums(vector<int>& arr) {
       int sum = 0;
       vector<int> ans;
       solve(0, arr, sum, ans);
       return ans;
    }
};