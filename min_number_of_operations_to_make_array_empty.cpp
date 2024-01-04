/*
You are given a 0-indexed array nums consisting of positive integers.

There are two types of operations that you can apply on the array any number of times:

Choose two elements with equal values and delete them from the array.
Choose three elements with equal values and delete them from the array.
Return the minimum number of operations required to make the array empty, or -1 if it is not possible.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int count=0;
        for (auto it:mp){
            if(it.second<2) return -1;
            if(it.second%3==0){
                count+=it.second/3;
                continue;
            }
            int value=it.second/3;
            if(it.second%2 ==0){
                if(value%2!=0){
                    value=value-1;
                }
            }
            else{
                if(value%2==0){
                    value=value-1;
                }
            }
            int res=value*3;
            count+=value;
            int remaning=it.second-res;
            if(remaning%2!=0) return -1;
            count+=remaning/2;

        }
        return count;
    }
};
int main(){
    Solution s;
    vector<int> nums={2,1,2,2,3,3};
    cout<<s.minOperations(nums);
    return 0;
}