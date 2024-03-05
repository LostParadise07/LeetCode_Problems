/*
Given a string s consisting only of characters 'a', 'b', and 'c'. 
You are asked to apply the following algorithm on the string any number of times:

Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
The prefix and the suffix should not intersect at any index.
The characters from the prefix and suffix must be the same.
Delete both the prefix and the suffix.
Return the minimum length of s after performing the above operation any number of times 
(possibly zero times).
*/
class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        
        while (left < right && s[left] == s[right]) {
            char current = s[left];
            while (left <= right && s[left] == current) {
                left++;
            }
        
            while (right >= left && s[right] == current) {
                right--;
            }
        }

        return max(0, right - left + 1);
    }
};