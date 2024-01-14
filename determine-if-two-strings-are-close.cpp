/*
Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, 
and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    
    bool closeStrings(string word1, string word2) {
        int n1=word1.length(),n2=word2.length();
        if(n1!=n2) return 0;
        vector<int>mp1(26);
        vector<int>mp2(26);
        for(int i=0;i<n1;i++){
            mp1[word1[i]-'a']++;
            mp2[word2[i]-'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            bool present1 = mp1[i] > 0;
            bool present2 = mp2[i] > 0;

            if ((present1 && !present2) || (!present1 && present2)) {
                return false;
            }
        }
        sort(mp1.begin(),mp1.end());
        sort(mp2.begin(),mp2.end());
        int i=0,j=0;
        for(int i=0;i<26;i++){
            if(mp1[i]!=mp2[i]) return false;
        }
        return true;
    }
};

