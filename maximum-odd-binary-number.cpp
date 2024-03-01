/*
You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum 
odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.

Note that the resulting string can have leading zeros.
*/
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0;
        int zeroes=0;
        for(auto it:s){
            if(it=='1'){
                ones++;
            }
            else{
                zeroes++;
            }
        }
        int i=0;
        while(ones-->1){
            s[i]='1';
            i++;
            
        }
        while(zeroes--){
            s[i++]='0';
        }
        s[i]='1';
        return s;
    }
};