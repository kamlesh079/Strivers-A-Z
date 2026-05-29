// https://leetcode.com/problems/reverse-pairs/

class Solution {
public:
    int countPairs(int low, int mid, int high, vector<int>& nums){
        int count = 0;

        int right = mid + 1;

        for(int i = low; i <= mid; i++){
            while(right <= high && (long long)nums[i] > 2LL * nums[right]) 
                right++;
            count += right - (mid + 1);
        }
        return count;
    }
    void merge(int low, int mid, int high, vector<int>& nums){
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }
        while(left <= mid) temp.push_back(nums[left++]);
        while(right <= high)temp.push_back(nums[right++]);

        for(int i = low; i <= high; i++) 
            nums[i] = temp[i - low];
    }
    int mergeSort(int l, int h, vector<int>& nums){
        int count = 0;
        if(l >= h) return count;
        int mid = l + (h - l)/2;

        count += mergeSort(l, mid, nums);
        count += mergeSort(mid + 1, h, nums);

        count += countPairs(l, mid, h, nums);
        merge(l, mid, h, nums);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(0, n - 1, nums);
    }
};