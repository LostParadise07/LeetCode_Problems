/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that 
is either directly below or diagonally left/right. Specifically, the next element from position 
(row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        if (n==1) return matrix[0][0];//edge case
        for (int i=n-2; i>=0; i--){
            for (int j=0; j < n; j++) {
                matrix[i][j]+=min({matrix[i+1][max(0, j-1)], matrix[i+1][j], matrix[i+1][min(n-1, j+1)]});
            }
        }
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};