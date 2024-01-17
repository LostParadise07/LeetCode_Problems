/*
Given an array of integers arr, return true if the number of occurrences of each value in 
the array is unique or false otherwise.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto it:mp){
            cout<<it.second<<" ";
        }
        cout<<endl;
        unordered_set<int> s;
        for(auto it:mp){
            if(it.second!=0 and s.find(it.second)!=s.end()) {
                cout<<" *************************";
                return false;
            }
            s.insert(it.second);
        }
        return true;
    }
};

