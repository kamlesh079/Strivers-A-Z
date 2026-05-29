// https://www.geeksforgeeks.org/problems/merge-sort/1

class Solution {
  public:
  
    void merge(vector<int>& arr, int l, int m, int r) {
        
        vector<int> temp;
        
        int i = l;
        int j = m + 1;
        
        // Merge both sorted halves
        while(i <= m && j <= r) {
            
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }
            else {
                temp.push_back(arr[j]);
                j++;
            }
        }
        // Remaining elements of left half
        while(i <= m) {
            temp.push_back(arr[i]);
            i++;
        }
        // Remaining elements of right half
        while(j <= r) {
            temp.push_back(arr[j]);
            j++;
        }
        // Copy temp back to original array
        for(int k = l; k <= r; k++) {
            arr[k] = temp[k - l];
        }
    }
    
    
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l >= r) return;
        int m = l + (r - l) / 2;
        
        // Left half
        mergeSort(arr, l, m);
        // Right half
        mergeSort(arr, m + 1, r);
        // Merge sorted halves
        merge(arr, l, m, r);
    }
};