// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

class Solution {
  public:
  
    int minSteps(vector<int>& arr, int start, int end) {
        
        if (start == end)
            return 0;
        
        int MOD = 1e3;
        
        vector<bool> vis(1000, false);
        queue<pair<int, int>> q;
        
        q.push({0, start});
        
        while(!q.empty()){
            auto[cost, node] = q.front();
            q.pop();
            
            if(node == end)
                return cost;
            
            for(int x : arr){
                int multi = (x * node) % MOD;
                
                if(!vis[multi]){
                    vis[multi] = true;
                    q.push({cost + 1, multi});
                }
                
            }
        }
        return -1;
        
    }
};