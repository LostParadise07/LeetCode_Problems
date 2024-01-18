/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
class Solution {
public:
int solve(int n,vector<int> &dp){
    if(n==0 || n==1 || n==2){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return solve(n,dp);
        if(n==1 or n==2){
            return n;
        }
        int first=1,second=1,third=0;
        for(int i=2;i<=n;i++){
            third=first+second;
            second=first;
            first=third;
        }
        return third;
    }
};