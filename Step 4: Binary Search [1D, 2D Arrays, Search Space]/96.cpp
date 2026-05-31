// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    bool isValid(int mid, vector<int>& nums, int threshold){
        int sum = 0;
        for(int x : nums) 
            sum += (x + mid - 1)/mid; // better
            // sum += ceil((double)x/mid);
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans = -1;

        int s = 1;
        int e = *max_element(nums.begin(), nums.end()); // why max element ? becouse beyond that ceil will have same val
        
        while(s <= e){
            int mid = s + (e - s)/2;
            if(isValid(mid, nums, threshold)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};