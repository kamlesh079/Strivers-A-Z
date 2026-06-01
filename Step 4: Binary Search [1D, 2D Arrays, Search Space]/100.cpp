// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

// "We check the minimum number of groups/studnet required for a given mid. If the required groups are less than or equal to k, then the partition is valid because we can always split some groups further to make more groups (up to k) while keeping every group sum ≤ mid."

class Solution {
  public:
    bool isValid(int mid, vector<int> &arr, int k){
        int pageCount = 0;
        int studentReq = 1;
        for(int x: arr){
            if(pageCount + x > mid){
                studentReq++;
                pageCount = 0;
                
            }
            pageCount += x;
        }
        // For a given mid, count minimum students required.
        // If required students <= k => allocation is possible.
        return studentReq <= k;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(n < k) return -1;
        
        int s = *max_element(arr.begin(), arr.end());
        int e = accumulate(arr.begin(), arr.end(), 0);
        
        int ans = -1;
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