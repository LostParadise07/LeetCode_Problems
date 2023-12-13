/*

Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 
and all other elements in row i and column j are 0 (rows and columns are 0-indexed).


*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(); 
        int n = mat[0].size(); 

        
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0); 

        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 1) {
                    rowCount[row]++; 
                    colCount[col]++; 
                }
            }
        }

        int ans = 0;

       
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 1) { 
                    if (rowCount[row] == 1 && colCount[col] == 1) {
                        
                        ans++;
                    }
                }
            }
        }

        return ans; 
    }
};
