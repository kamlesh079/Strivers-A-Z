// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

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
    int countFreq(vector<int>& arr, int target) {
        int i = firstPos(arr, target);
        if(i == -1) return 0; // when element not found
        int j = lastPos(arr, target);
        
        return j - i + 1;
    }
};
