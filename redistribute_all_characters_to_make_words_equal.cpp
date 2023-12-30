/*
You are given an array of strings words (0-indexed).

In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, 
and move any character from words[i] to any position in words[j].

Return true if you can make every string in words equal using any number of operations, and false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> res(26);
        for(int i=0;i<words.size();i++){

            for(int j=0;j<words[i].length();j++){
                char ch=words[i][j];
                res[ch-'a']++;

            }
        }
        for(int i=0;i<res.size();i++){
            if(res[i]%words.size() >0 ) return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<string> words={"abc","aabc","bc"};
    cout<<s.makeEqual(words);
    return 0;
}