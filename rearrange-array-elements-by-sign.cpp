/*
You are given a 0-indexed integer array nums of even length consisting of an equal number of 
positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>v1,v2,ans;
        
        for(int i =0;i<nums.size();i++){
            if(nums[i]>0)v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }
        int ind1=0,ind2=0;
        

        while(ind2<nums.size()/2){
            ans.push_back(v1[ind1]);
            ind1++;
            ans.push_back(v2[ind2]);
            ind2++;
        }
        return ans;
    }
};

