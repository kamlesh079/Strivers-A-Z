

// ******* Same as book allocation problem ******

class Solution {
  public:
    bool isValid(int mid, vector<int>& arr, int k){
        int sum = 0;
        int count = 1;
        for(int x : arr){
            if(sum + x > mid){
                count++;
                sum = 0;
            }
            sum += x;
        }
        return count <= k;
    }
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        
        int ans = -1;
        
        int s = *max_element(arr.begin(), arr.end()); // enough to complete any of the task
        int e = accumulate(arr.begin(), arr.end(), 0);
        while(s <= e){
            int mid = s + (e - s)/2;
            
            if(isValid(mid, arr, k)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};