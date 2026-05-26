// https://leetcode.com/problems/pascals-triangle/description/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for(int i = 0; i < numRows; i++){
            vector<int> row(i + 1, 1);
            for(int j = 1; j < i; j++){ //temp.size() - 1 => i + 1 - 1 = i
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};


// https://leetcode.com/problems/pascals-triangle-ii/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        vector<int> row;
        row.push_back(1);
        long long res = 1;
        // generate next values from previous
        // nCr = nC(r-1) * (n-r+1) / r
        for(int r = 1; r <= n; r++) {
            res = res * (n - r + 1);
            res = res / r;
            row.push_back(res);
        }
        return row;
    }
};