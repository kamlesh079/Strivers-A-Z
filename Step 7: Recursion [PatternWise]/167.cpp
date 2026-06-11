// https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1

// This will give TLE as it is not optimised yet
class Solution {
  public:
    bool solve(vector<int>& arr, int target, int id, int sum) {
        if(id == arr.size())
            return sum == target;
    
        bool include = solve(arr, target, id + 1, sum + arr[id]);
    
        bool exclude = solve(arr, target, id + 1, sum);
    
        return include || exclude;
    }
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        return solve(arr, k, 0, 0);
        
    }
};