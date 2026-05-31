// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

class Solution {
  public:
    long long powerN(long long b, int p){
        long long res = 1;
        while(p){
            if(p & 1) res *= b;
            b *= b;
            p >>= 1;
        }
        return res;
    }
    int nthRoot(int n, int m) {
        
        int s = 0;
        int e = m;
        while(s <= e){
            long long mid = s + (e - s)/2;
            long long multiple = powerN(mid, n); // striver used 'for' loop to cal the power, so its up to u what u prefer 
            if(multiple == m) return mid;
            else if(multiple < m){
                s = mid + 1;
            }
            else e = mid - 1;
        }
        return -1;
    }
};