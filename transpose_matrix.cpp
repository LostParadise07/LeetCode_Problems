/*

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal,
switching the matrix's row and column indices.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int n = A.size(); // row
        int m = A[0].size(); // col
        
        if(n==m){
        
            for (int i = 0; i < n; i++)
                for (int j = 0 ; j<=i;j++)
                    swap(A[i][j], A[j][i]);
            
            return A;
        }
        
        vector<vector<int>> arr(m, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
               arr[j][i] = A[i][j];
        
        return arr;
    }
};