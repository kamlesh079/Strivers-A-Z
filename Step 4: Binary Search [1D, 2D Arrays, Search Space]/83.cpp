// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

// # Floor in sorted array 
// Pattern -> similar to upper and lower bound
class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int n = arr.size();
        
        int s = 0;
        int e = n - 1;
        int ans = -1;// when not found;
        
        while(s <= e){
            int mid = s + ((e - s) >> 1);
            
            if(arr[mid] <= x){
                ans = mid;
                s = mid + 1;
            }
            else e = mid -1;
            
        }
        
        return ans;
        
    }
};

// https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1
// # ceil in sorted array 

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
       int n = arr.size();
        
        int s = 0;
        int e = n - 1;
        int ans = -1;// when not found;
        
        while(s <= e){
            int mid = s + ((e - s) >> 1);
            
            if(arr[mid] >= x){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
            
        }
        
        return ans;
    }
};