/*
You are given two strings of the same length s and t. In one step you can choose any 
character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different 
(or the same) ordering.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> st;
        for(int i=0;i<s.length();i++){
            st[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            st[t[i]]--;
        }
        int count=0;
        for(auto it:st){
            count+=abs(it.second);
        }
        return count/2;
    }
};

int main(){
    string s="bab",t="aba";
    
    Solution sol;
    cout<<sol.minSteps(s,t)<<endl;
    return 0;
}