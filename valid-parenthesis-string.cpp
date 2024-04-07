/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis 
'(' or an empty string "".
*/
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> starIndex;
        stack<int> stackIndex;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                stackIndex.push(i);
            }
            else if(s[i] == '*')
            {
                starIndex.push(i);
            }
            else if(s[i] == ')')
            {
                if(stackIndex.empty() && starIndex.empty()) 
                    return false;
                else if(!stackIndex.empty()) 
                    stackIndex.pop();
                else    
                    starIndex.pop();;
            }
        }

        while(!stackIndex.empty())
        {
            if(starIndex.empty()) return false;
            if(stackIndex.top() > starIndex.top()) return false;
            stackIndex.pop();
            starIndex.pop();
        }

        return true;
    }
};