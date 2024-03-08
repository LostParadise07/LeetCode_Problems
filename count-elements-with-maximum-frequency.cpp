/*
You are given an array nums consisting of positive integers.
Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
The frequency of an element is the number of occurrences of that element in the array.
*/
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101]={0}, maxF=0;
        for (int x: nums){
            freq[x]++;
            maxF=max(maxF, freq[x]);
        }
        int ans=0;
        for (int f: freq){
            if (f==maxF)
                ans+=f;
        }
        return ans;
    }
};