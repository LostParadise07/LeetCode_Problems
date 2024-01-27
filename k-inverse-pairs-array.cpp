/*
For an integer array nums, an inverse pair is a pair of integers [i, j] 
where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consist of numbers from 1 to n 
such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.
*/
class Solution {
public:
     int kInversePairs(int n, int k) {
        const int MOD = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (j == 0) {
                    dp[i][j] = 1;
                } else {
                    int val = (dp[i - 1][j] + MOD - (j - i >= 0 ? dp[i - 1][j - i] : 0)) % MOD;
                    dp[i][j] = (dp[i][j - 1] + val) % MOD;
                }
            }
        }

        return (dp[n][k] + MOD - (k > 0 ? dp[n][k - 1] : 0)) % MOD;
    }
};