/*
Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.
*/
class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        vector<pair<int, char>> v;
        string ans = "";
        for(auto ch: s){
            mp[ch]++;
        }
        for(auto i: mp){
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        for(auto i: v){
            while(i.first--) ans += i.second;
        }
        return ans;
    }
};