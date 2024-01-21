/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from 
robbing each of them is that adjacent houses have security systems connected and it will 
automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.
*/
class Solution {
public:
    // int solve(vector<int> arr,vector<int> &dp,int n){
    //     if(n<0){
    //         return 0;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     return dp[n]=max(arr[n]+solve(arr,dp,n-2),solve(arr,dp,n-1));
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take =nums[i];
            if(i>1) take+=prev2;
            int nottake=prev1;
            int curr=max(take,nottake);
            
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};