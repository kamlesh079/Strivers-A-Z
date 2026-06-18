// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution {
  public:
  
    int merge(int l, int mid, int h, vector<int> &arr){
        vector<int> ans;
        int i = l;
        int j = mid + 1;
        
        int count = 0;
        while( i <= mid && j <= h){
            if(arr[i] <= arr[j]){
                ans.push_back(arr[i]);
                i++;
            }
            else{
                // all remaining left elements are greater than arr[right]
                count += mid - i + 1;
                ans.push_back(arr[j]);
                j++;
            }
        }
        while(i <= mid) ans.push_back(arr[i++]);
        while(j <= h) ans.push_back(arr[j++]);
        
        for(int i = l; i <= h; i++){
            arr[i] = ans[i - l];
        }
        return count; // yaha pe return karna bhool gaya tha
    }
    
    int mergeSort(int l, int h, vector<int> &arr){
        int count = 0;

        if(l >= h) return count;

        int mid = l + (h - l)/2;
        count += mergeSort(l, mid, arr);
        count += mergeSort(mid + 1, h, arr);
        count += merge(l, mid, h, arr);
        return count;
    }
    int inversionCount(vector<int> &arr) {
        return mergeSort(0, arr.size() - 1, arr);
 
    }
};