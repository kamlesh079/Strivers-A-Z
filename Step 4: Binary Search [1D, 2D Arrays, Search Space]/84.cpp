// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    // First Position
    int firstPos(vector<int>& nums, int target){
        int n = nums.size();

        int s = 0;
        int e = n - 1;
        int firstId = -1;
        while(s <= e){
            int mid = s + ((e - s) >> 1);
            if(nums[mid] == target){
                firstId = mid;
                e = mid - 1;
            }
            else if(target > nums[mid]){
                s = mid + 1;
            }
            else
                e = mid - 1;
        }
        return firstId;
    }
    // Last Position
    int lastPos(vector<int>& nums, int target){
        int n = nums.size();

        int s = 0;
        int e = n - 1;
        int lastId = -1;
        while(s <= e){
            int mid = s + ((e - s) >> 1);
            if(nums[mid] == target){
                lastId = mid;
                s = mid + 1;
            }
            else if(target > nums[mid]){
                s = mid + 1;
            }
            else
                e = mid - 1;
        }
        return lastId;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int id1 = firstPos(nums, target);
        int id2 = lastPos(nums, target);
        return {id1, id2};
    }
};