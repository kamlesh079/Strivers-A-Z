https://www.geeksforgeeks.org/problems/bubble-sort/1

class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
       for(int i = 0; i < arr.size(); ++i){
           int min_id = i; // let
           for(int j = i + 1; j < arr.size(); ++j){
               if(arr[j] < arr[min_id]) min_id = j;
           }
           swap(arr[min_id], arr[i]);
       }
        
    }
};