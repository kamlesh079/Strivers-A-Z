// https://leetcode.com/problems/single-element-in-a-sorted-array/

// This is what i came up with, but there is simpler solution too...
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int s = 0;
        int e = n - 1;
        while (s < e) {
            int mid = s + ((e - s) >> 1);
            if (mid + 1 <= e && nums[mid] == nums[mid + 1]) {
                // if mid is odd - unique is on left of mid
                if (mid & 1)
                    e = mid - 1;
                // if mid is even - unique is on right of mid
                else
                    s = mid + 2;
            } else if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                // if mid is odd - unique is on right side of mid
                if (mid & 1)
                    s = mid + 1;
                // if mid is even -> unique is on left side of mid
                else
                    e = mid - 2;
            }
            else return nums[mid];
        }
        return nums[s];
    }
};

// Sorter version of above with less if else
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int s = 0;
        int e = n - 1;

        while (s < e) {
            int mid = s + ((e - s) >> 1);

            // Make mid even so that mid and mid+1
            // represent the expected start of a pair.
            if (mid & 1) mid--;

            // If nums[mid] == nums[mid+1], then the pair is valid.
            // This means we are still on the left side of the single element,
            // where pairs start at even indices.
            // Therefore, the single element must be after this pair.
            if (nums[mid] == nums[mid + 1]) {
                s = mid + 2;
            }
            else {
                // The expected pair is broken.
                // This means we have reached the single element
                // or crossed to its right side.
                // Therefore, the answer lies at mid or somewhere to the left.
                e = mid;
            }
        }

        return nums[s];
    }
};