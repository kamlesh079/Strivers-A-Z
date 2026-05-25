// https://leetcode.com/problems/next-permutation/description/

/*
NEXT PERMUTATION INTUITION (SUPER EASY)

Goal:
Find the next GREATER arrangement of numbers.
Example:
1 2 3 -> 1 3 2

---------------------------------------------------

STEP 1 : Find the BREAKPOINT (dip)

Go from RIGHT side and find first index where:

arr[i] < arr[i+1]

Why from right?
Because right side changes give SMALLER increase.
We want JUST NEXT greater permutation.

Example:
1 2 7 4 3 1

From right:
4 > 3 > 1  (decreasing)

Then:
2 < 7  <-- breakpoint found

So idx = 1 (value = 2)

---------------------------------------------------

STEP 2 : Find slightly bigger element

Now from RIGHT side find first element bigger than arr[idx].

Why?
Because we want smallest possible increase.

Example:
Right side = 7 4 3 1
Smallest bigger than 2 = 3

Swap:
1 3 7 4 2 1

---------------------------------------------------

STEP 3 : Reverse the right part

Why reverse?
Because right side is currently in DESCENDING order
(largest possible arrangement).

To get NEXT permutation,
we must make it SMALLEST possible.

Current:
7 4 2 1

Reverse:
1 2 4 7

Final answer:
1 3 1 2 4 7

---------------------------------------------------

SPECIAL CASE

If no breakpoint found:

Example:
3 2 1

This means array is already largest permutation.

So simply reverse whole array:

1 2 3

---------------------------------------------------

MEMORY TRICK:

Find dip -> swap slightly bigger -> reverse tail
OR
Breakpoint -> Swap -> Reverse
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find breakpoint
        int pivot = -1;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                pivot = i;
                break;
            }
        }
         // Already largest permutation
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find next greater element
        for(int i = n - 1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }
        // Step 3: Reverse right part
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};