// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int platforms = 1;
        int i = 1;
        int j = 0;
        
        int ans = 1;
        
        while(i < arr.size() && j < dep.size()){
            if(arr[i] <= dep[j]){
                platforms++;
                i++;
            }
            else{
                platforms--;
                j++;
            }
            ans = max(ans, platforms);
        }
        return ans;
        
    }
};
