// subarray with maximum subarray sum (extended version)
// https://leetcode.com/problems/maximum-subarray/description/ 

#include <iostream>
#include <vector>
using namespace std;

// # Kadane's Algorithm
int maxSubArray(vector<int>& nums){
    int maxSum = INT_MIN;
    int temp = 0;
    for(const int& x : nums){
        temp += x;
        maxSum = max(maxSum, temp);
        
        if(temp < 0) temp = 0;
    }
    return maxSum;
}

// # Kadane's Algorithm (Extended Version) 
// Normal Kadane's Algorithm only keep track of the maximum sum, but in this extended version we also keep track of the start and end indices of the subarray that gives the maximum sum.

int maxSubArrayExtended(vector<int>& nums){
    int maxSum = INT_MIN;
    int temp = 0;

    int start = 0; // temporary start index
    int maxStart = 0; // start index of the maximum subarray
    int maxEnd = 0; // end index of the maximum subarray

    for(int i = 0; i < nums.size(); ++i){
        if(temp == 0) start = i;

        temp += nums[i];
        
        if(temp > maxSum){
            maxSum = temp;
            maxStart = start;
            maxEnd = i;
        }

        if(temp < 0) temp = 0;
    }
    
    for(int i = maxStart; i <= maxEnd; i++) cout << nums[i] << " ";
    cout << endl;

    return maxSum;
}

int main(){
    // vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4}; // 6, {4, -1, 2, 1}
    vector<int> nums = {5,4,-1,7,8}; 
    cout << maxSubArrayExtended(nums) << endl;
    return 0;
}