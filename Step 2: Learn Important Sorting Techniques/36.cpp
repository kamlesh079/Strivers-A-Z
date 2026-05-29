// https://www.geeksforgeeks.org/problems/bubble-sort/1

class Solution {
  public:
    void fun(vector<int>& arr, int n){
        if(n == 1) return;
        
        // first pass
        for(int i = 0; i < n - 1; i++){
            if(arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
        // recrsive for rest of element
        fun(arr, n - 1);
        
    }
    void bubbleSort(vector<int>& arr) {
        fun(arr, arr.size());
    }
};