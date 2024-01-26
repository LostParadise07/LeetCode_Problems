/*
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. 
You are allowed to move the ball to one of the four adjacent cells in the grid 
(possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the 
ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.
*/
class Solution {
public:
    int mod=1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(int m, int n, int maxMove, int i, int j){
        if(i<0 or j<0 or i>=m or j>=n){
            return 1;
        }
        if(maxMove==0) return 0;
        if(dp[i][j][maxMove]!=-1) return dp[i][j][maxMove];
        int left=0,right=0,top=0,bottom=0;
        
        left=solve(m,n,maxMove-1,i,j-1);
        right=solve(m,n,maxMove-1,i,j+1);
        top=solve(m,n,maxMove-1,i-1,j);
        bottom=solve(m,n,maxMove-1,i+1,j);
        
        return dp[i][j][maxMove]= ((top+bottom)%mod + (left+right)%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return solve(m,n,maxMove,startRow,startColumn);
    }
};