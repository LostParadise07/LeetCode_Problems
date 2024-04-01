/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

 
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        for(int i=s.length()-1;i>=0;i--){

            if(s[i]==' ' and count>0 ){
                break;
            }
            else if(s[i]!=' '){
                count++;
            }
        }
        return count;
    }
};