// https://leetcode.com/problems/find-a-peak-element-ii/

class Solution {
public:
    int findRow(int col, vector<vector<int>>& mat){
        int row = 0;
        for(int i = 0; i < mat.size(); i++){
            if(mat[i][col] > mat[row][col])
                row = i;
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int s = 0;
        int e = m - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            int row = findRow(mid, mat);
            
            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[row][mid + 1] : -1;

            if(mat[row][mid] > left && mat[row][mid] > right) return {row, mid};
            else if(mat[row][mid] < right) s = mid + 1;
            else e = mid - 1;

        }
        return {-1, -1};
    }
};

// ######### Tiny Memory Notes #########
// 1. BS on columns

// 2. Find maximum element in middle column

// 3. Since it's column maximum:
//    up < curr and down < curr

// 4. Only check left and right

// curr > left && curr > right -> peak

// right > curr -> go right

// left > curr -> go left