// https://leetcode.com/problems/kth-missing-positive-number/description/

// # Using BS(Binary Search Method)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            int missing = arr[mid] - (mid + 1);
            
            if(missing < k) low = mid + 1;
            else high = mid - 1;
        }

        return low + k;
    }
};