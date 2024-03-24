/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 


*/class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
  
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[nums[i]%n]=nums[nums[i]%n]+n;
        }    
        for(int i=0;i<n;i++){
            if(nums[i]>2*n)
                return i;
        }
        return -1;
    }
};