// https://www.geeksforgeeks.org/problems/quick-sort/1
class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
       if(low < high){
           int pId = partition(arr, low, high);
           quickSort(arr, low, pId - 1);
           quickSort(arr, pId + 1, high);
       }
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        
        int i = low - 1;
        for(int j = low; j < high; j++){
            if(arr[j] < pivot){
                i++;
                swap(arr[j], arr[i]);
            }
        }
        // swap(arr[i+1], pivot); // pivot stores only the value, not the actual array element, so swap with arr[high], not pivot.
        swap(arr[i+1], arr[high]);
        return i + 1;
    }
};