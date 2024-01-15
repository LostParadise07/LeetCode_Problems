/*
You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the 
player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.
*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>mp;
        int n=matches.size();
        for(int i=0;i<n;i++){
            mp[matches[i][0]]=0;
            mp[matches[i][1]]=0;
        }
        for(int i=0;i<n;i++){
            mp[matches[i][1]]++;
        }
        vector<vector<int>> ans;
        vector<int> temp1,temp2;
        for(auto it :mp){
            if(it.second==0) temp1.push_back(it.first);
            if(it.second==1) temp2.push_back(it.first);
        }
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};