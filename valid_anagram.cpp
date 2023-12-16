/*

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a 
different word or phrase, typically using all the original letters exactly once.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;

        int map[26]={0};
        for(int i=0;i<s.length();i++){
            map[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            map[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(map[i]!=0) return false;
        }
        return true;
    }
};