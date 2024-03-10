/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool>mp;
        for(auto it :nums1){
            mp[it]=true;
        }
        vector<int> ans;
        for(auto it:nums2){
            if(mp[it]){
                ans.push_back(it);
                mp[it]=false;
            }
        }
        return ans;
    }
};