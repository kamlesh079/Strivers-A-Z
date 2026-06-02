// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n = a.size();
        int m = b.size();
        
        if(n > m) return kthElement(b, a, k);
        
        // *********************************
        // cut1 = number of elements chosen from a.
        
        // It cannot:
        
        // be negative
        // exceed n
        // make cut2 negative
        // make cut2 exceed m
        
        // Combining all those restrictions gives:
        
        // max(0, k-m) <= cut1 <= min(k,n)
        
        // *********************************
        
        int s = max(0, k - m);
        int e = min(k, n);
        int left = k;
        
        while(s <= e){
            int mid = s + (e - s)/2;
            
            int cut1 = mid;
            int cut2 = left - cut1;
            
            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int r1 = (cut1 == n) ? INT_MAX : a[cut1];
            
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int r2 = (cut2 == m) ? INT_MAX : b[cut2];
            
            // valid cut
            if(l1 <= r2 && l2 <= r1){
                return max(l1, l2);
            }
            else if(l1 > r2) e = mid - 1;
            else s = mid + 1;
        }
        return 0;
        
    }
};