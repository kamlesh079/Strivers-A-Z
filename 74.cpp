// https://leetcode.com/problems/merge-sorted-array/ (This is what is covered by striver)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // last id of num1
        int j = n - 1; // last id of num2
        int k = m + n - 1; // // k is the last index of nums1 (including 0 placeholders)
        
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else nums1[k--] = nums2[j--];
        }
        while( j>= 0) nums1[k--] = nums2[j--];

    }
};



// $$$$$$$ This is kind of same but little Diff $$$$$$
// #############################################################################################
// https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

// not optimal
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        // code here
        for(int i = m - 1; i >= 0; i--){
            if(b[i] < a[n - 1]){
                int num = b[i];
                swap(b[i], a[n - 1]);
                
                int j = n - 2;
                while(j >= 0 && a[j] > num){
                    a[j + 1] = a[j];
                    j--;
                }
                    
                a[j + 1] = num;
            }
        }
        
    }
};

// Optimal - Gap Method (similar to Shell Sort)
class Solution {
  public:
    int nextgap(int n){
        if(n <= 1) return 0;
        return (n / 2) + (n % 2);
    }
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        
        int gap = nextgap(n + m);
        
        while(gap > 0){
            
            int left = 0;
            int right = left + gap;
            while(right < m + n){
                // both pointer in a
                if(left < n && right < n){
                    if(a[left] > a[right]) 
                        swap(a[left], a[right]);
                }
                // left in a, right in b
                else if(left < n && right >= n){
                    if(a[left] > b[right - n]) 
                        swap(a[left], b[right - n]);
                }
                // both pointers in b
                else
                    if(b[left - n] > b[right - n])
                        swap(b[left - n], b[right - n]);
                left++;
                right++;
            }
            gap = nextgap(gap);
        }
        
    }
};