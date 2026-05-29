
// 1. Max Product + Min Product (Interview Standard)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0]; // max product ending here
        int mini = nums[0]; // min product ending here

        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            int curr = nums[i];

            int tempMax = max({
                curr,
                curr * maxi,
                curr * mini
            });

            int tempMin = min({
                curr,
                curr * maxi,
                curr * mini
            });

            maxi = tempMax;
            mini = tempMin;

            ans = max(ans, maxi);
        }

        return ans;
    }
};

// Same Logic Using Swap Trick
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] < 0)
                swap(maxi, mini);

            maxi = max(nums[i], nums[i] * maxi);
            mini = min(nums[i], nums[i] * mini);

            ans = max(ans, maxi);
        }

        return ans;
    }
};

// 2. Prefix + Suffix Method
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        long long pre = 1;
        long long suf = 1;

        int ans = INT_MIN;

        for(int i = 0; i < n; i++) {

            // restart after zero
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;

            pre *= nums[i];

            suf *= nums[n - i - 1];

            ans = max(ans, (int)max(pre, suf));
        }

        return ans;
    }
};