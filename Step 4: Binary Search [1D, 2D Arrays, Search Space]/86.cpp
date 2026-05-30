// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int findPivot(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        while (s < e) {
            int mid = s + ((e - s) >> 1);
            if(nums[mid] > nums[e]) s = mid + 1;
            else e = mid;
        }
        return s;
    }
    int BS(int s, int e, int target, vector<int>& nums) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (target == nums[mid])
                return mid;
            else if (nums[mid] > target)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = findPivot(nums); // O(logn)
        
        if (target >= nums[pivot] && target <= nums[n - 1])
            return BS(pivot, n - 1, target, nums); // O(logn)

        return BS(0, pivot - 1, target, nums); // O(logn)
    }
};


// # Using one BS
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid] == target) return mid;
            // if left part is sorted
            if(nums[s] <= nums[mid]){
                if(target >= nums[s] && target < nums[mid]) e = mid - 1;
                else s = mid + 1;
            }
            // if right part is sorted
            else{
                if(target > nums[mid] && target <= nums[e]) s = mid + 1;
                else e = mid - 1;
            }
        }
        return -1;
    }
};