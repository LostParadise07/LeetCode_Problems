/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 
*/
class Solution {
public:
    
    int countSubarraysWithAtMostKDistinct(vector<int>& nums, int k){
        int n=nums.size();
        
        unordered_map<int, int> mp;
        
        int i=0, j=0;
        
        int c=0;
        
        while(j<n){
            mp[nums[j]]++;
            
            while(i<=j && mp.size()>k){
                if(--mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            
            c += (j-i+1);
            
            j++;
        }
        
        return c;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarraysWithAtMostKDistinct(nums,k)-countSubarraysWithAtMostKDistinct(nums,k-1);
    }
};