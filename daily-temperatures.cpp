/*
Given an array of integers temperatures represents the daily temperatures, return an array answer 
such that answer[i] is the number of days you have to wait after the ith day to get a warmer 
temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

*/ 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size(),0);
        stack <int> stk;  
        for(int i=temp.size()-1;i>=0;i--){
            if(stk.empty()){
                stk.push(i);
                ans[i] = 0;
            }
            else{
                while(!stk.empty() && temp[i]>=temp[stk.top()]){
                    stk.pop();
                }
                if(stk.empty()){
                    ans[i] = 0;
                }
                else{
                    ans[i] = stk.top()-i;
                }
                stk.push(i);
            }
            
        }
        return ans;
    }
};