/*
Given an array nums containing n distinct numbers in the range [0, n], return the only 
number in the range that is missing from the array.
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<bool> res(n,0);
        for(int i=0;i<n;i++){
            res[nums[i]]=true;
        }
        for(int i=0;i<n;i++){
            if(!res[i]){
                return i;
            }
        }
        return n;
    }
};