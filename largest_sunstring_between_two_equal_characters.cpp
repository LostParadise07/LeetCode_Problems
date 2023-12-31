/*
Given a string s, return the length of the longest substring between two equal characters, 
excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.
*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int last[26] = {0}, ans = -1;
        for(int i = 0; i < s.size(); ++i) 
            last[s[i] - 'a'] = i;
        for(int i = 0; i < s.size(); ++i) 
            ans = max(ans, last[s[i] - 'a'] - i - 1);
        return ans;

    }
};