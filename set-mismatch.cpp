/*
You have a set of integers s, which originally contains all the numbers from 1 to n. 
Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int value=0;
        for(int i=0;i<nums.size();i++){
            value^=nums[i]^(i+1);
        }
        vector<int>ans(2);
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int res=0;
        for(auto it:mp){
            if(it.second==2){
                res=it.first;
            }
        }
        ans[0]=res;
        ans[1]=res^value;
        return ans;
    }
};