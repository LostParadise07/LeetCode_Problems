/*
Given an integer n, return the least number of perfect square numbers that sum to n.
A perfect square is an integer that is the square of an integer; in other words, it is 
the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares 
while 3 and 11 are not.
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for(int i=1; i*i<=n; i++){
            dp[i*i] = 1;
        }
        for(int i=1; i<=n; i++){
            if(dp[i] == 1) continue;
            int root = sqrt(i), mn = INT_MAX;
            for(int j=1; j<=root; j++){
                mn = min(mn, dp[j*j] + dp[i - j*j]);
            }
            dp[i] = mn;
        }
        return dp[n];
    }
};