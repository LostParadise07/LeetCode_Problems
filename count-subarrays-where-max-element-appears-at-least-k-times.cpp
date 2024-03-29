/*
You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx=INT_MIN;
        for(auto it : nums){
            mx=max(mx,it);
        }
        int n=nums.size();
        int freq=0;
        int start=0;
        long long ans=0;
        for(int end=0;end<n;end++){
            // Growing Phase
            if(nums[end]==mx)
                freq++;
            while(freq==k){//Shrinking Phase
                if(nums[start]==mx)
                    freq--;
                start++;
            }
            ans+=start;
        }
        return ans;

    }
};