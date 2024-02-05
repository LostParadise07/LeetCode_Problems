/*
Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(freq[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};