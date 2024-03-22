/*
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        stack<int> s;
        ListNode* curr=head;
        while(curr!=NULL){
            int value=curr->val;
            s.push(value);
            curr=curr->next;
        }
        curr=head;
        
        while(curr!=NULL){
            
            int val1=curr->val;
            int val2=s.top();
            if(val1!=val2)
            {
                return false;
            }
            curr=curr->next;
            s.pop();
        }
        return true;
    }
};