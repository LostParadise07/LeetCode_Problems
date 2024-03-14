/*
Given a positive integer n, find the pivot integer x such that:
The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be 
at most one pivot index for the given input.
*/
class Solution {
public:
    int sum(int s,int e){
        int n=e-s+1;
        return ((n)*(s+e))/2;
    }
    int pivotInteger(int n) {
        int s=1;
        int e=n;
        while(s<=e){
            int mid=(s+e)/2;
            // cout<<mid;
            if(sum(1,mid)==sum(mid,n)){
                
                return mid;
            }
            else if(sum(1,mid)<sum(mid+1,n)){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return -1;
    }
};