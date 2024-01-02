/*
You are given an integer array nums. You need to create a 2D array from nums satisfying the 
following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.
 */
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int maxi=0;
        for(auto it:mp){
            maxi=max(maxi,it.second);
        }
        vector<vector<int>>ans(maxi);
        for(int i=0;i<n;i++){
            int res=mp[nums[i]];
            ans[res-1].push_back(nums[i]);
            mp[nums[i]]--;
        }
        return ans;
    }
};