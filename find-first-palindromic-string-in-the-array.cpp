/*
Given an array of strings words, return the first palindromic string in the array. 
If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.
*/
class Solution {
public:
    bool pal(string str){
        int s=0;
        int e=str.length()-1;
        while(s<e){
            if(str[s]!=str[e]) return false;
            s++;e--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto it:words){
            if(pal(it)){
                return it;
            }
        }
        return "";
    }
};