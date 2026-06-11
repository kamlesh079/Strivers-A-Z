// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1


// This will Give TLE 
// We will optimise later Using DP
class Solution {
public:
    void solve(vector<int>& arr,int target,int id, int sum, int& count){
        if(id == arr.size()){
            if(sum == target)
                count++;
            return;
        }
        
        // Include
        solve(arr, target, id + 1, sum + arr[id], count);

        // Exclude
        solve(arr, target,id + 1,sum, count);
    }
    
    // or
    int solve(vector<int>& arr,int target,int id, int sum){
        if(id == arr.size()){
            return sum == target;
        }
        
        // Include
        int case1 = solve(arr, target, id + 1, sum + arr[id]);

        // Exclude
        int case2 = solve(arr, target,id + 1,sum);
        return case1 + case2;
    }

    int perfectSum(vector<int>& arr, int target) {
        int count = 0;
        
        solve(arr, target, 0, 0, count);
        
        return count;
    }
};