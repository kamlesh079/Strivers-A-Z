// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int s = INT_MAX;
        int e = INT_MIN;
        for(int i = 0; i < n; i++){
            s = min(s, mat[i][0]);
            e = max(e, mat[i][m - 1]);
        }
        
        int req = n*m / 2;
        
        while(s <= e){
            int mid = s + (e - s)/2;
            
            int count = 0;
            for(int i = 0; i < n; i++){
                count += upper_bound( mat[i].begin(), mat[i].end(),mid) - mat[i].begin();
            }
            if (count <= req) s = mid + 1;
            else {
                e = mid - 1;
            }
        }
        return s;
        
    }
};