// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);

        int s = 0;
        int e = n;
        int left = (m + n + 1)/2; // +1 so that left part has extra element in case of odd
        while(s <= e){
            int mid = s + (e - s)/2;

            int cut1 = mid;// it is redundant but for no cofusion i wrote this
            int cut2 = left - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
            int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];

            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];
            int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];

            if(l1 <= r2 && l2 <= r1){
                // if total count is odd
                if((n + m) & 1) return max(l1, l2);
                // if total count is even -> left side's max and right sides min
                return (max(l1,l2) + min(r1, r2)) /(double) 2;
            }
            else if(l1 > r2) e = mid - 1;
            else s = mid + 1;
        }
        return 0;
    }
};