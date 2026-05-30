// https://www.codechef.com/practice/course/binary-search/INTBINS01/problems/ROTATIONARAY?tab=statement

// Pattern -> finding minimum element idx as we did in pre question of BS
class Solution {
public:
    int countRotations(const vector<int>& nums) {
       int s = 0;
       int e = nums.size() - 1;
       while(s < e){
           int mid = s + ((e - s) >> 1);
           if(nums[mid] > nums[e]) s = mid + 1;
           else e = mid;
       }
       return s;
        
    }
};
