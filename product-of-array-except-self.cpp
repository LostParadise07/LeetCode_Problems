/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all 
the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
        vector<int> prefix(n); 
        prefix[0] = nums[0];
        
        vector<int> suffix(n); 
        suffix[n-1] = nums[n-1];
        
        vector<int> ans(n, 1);
        
        for(int i=1; i<n; i++) {
            prefix[i] = nums[i] * prefix[i-1];
            suffix[n-i-1] = suffix[n-i] * nums[n-i-1];
        }
        
        for(int i=0; i<n; ++i) {
            if(i)
            ans[i] *= prefix[i-1];
            if(i+1<n) 
            ans[i] *= suffix[i+1];
        }
    
        return ans;
    }
};