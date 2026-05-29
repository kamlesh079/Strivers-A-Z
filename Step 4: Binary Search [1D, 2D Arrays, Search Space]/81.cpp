// https://www.geeksforgeeks.org/problems/implement-upper-bound/1

class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
       int n = arr.size();
       // upper Bound -> element that is just greater than the target

        int s = 0;
        int e = n - 1;
        int ansId = n; // Why? Read the Note in the Question
        
        while(s <= e){
            int mid = s + (e - s)/2;
            if(arr[mid] > target){
                ansId = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
    }
};
