// https://www.geeksforgeeks.org/problems/insertion-sort/1

class Solution {
  public:
    void fun(vector<int>& arr, int i){
        if(i == arr.size())
            return;
        int key = arr[i];
        int j = i - 1;
        while( j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        
        fun(arr, i + 1);
    }
    void insertionSort(vector<int>& arr) {
        fun(arr, 1);
    }
};