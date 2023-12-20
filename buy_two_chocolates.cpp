/*
You are given an integer array prices representing the prices of various chocolates in a store. 
You are also given a single integer money, which represents your initial amount of money.

You must buy exactly two chocolates in such a way that you still have some non-negative leftover 
money. You would like to minimize the sum of the prices of the two chocolates you buy.

Return the amount of money you will have leftover after buying the two chocolates. If there is 
no way for you to buy two chocolates without ending up in debt, return money. Note that the 
leftover must be non-negative.


*/

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // int mini1=min(prices[0],prices[1]);
        // int mini2=max(prices[0],prices[1]);
        // for(int i=2;i<prices.size();i++){
        //     if(prices[i]<mini1){
        //         mini2=mini1;
        //         mini1=prices[i];
        //     }
        //     else if(prices[i]<mini2){
        //         mini2=prices[i];
        //     }
        // }

        // int minicost=mini1+mini2;
        // if(minicost<=money){
        //     return money-minicost;
        // }
        // return money;
        int mini1=INT_MAX;
        int mini2=INT_MAX;
        int index=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mini1){
                mini1=prices[i];
                index=i;
            }
        }

        for(int i=0;i<prices.size();i++){
            if(i!=index){
                mini2=min(mini2,prices[i]);
            }
        }

        if(mini1+mini2>money) return money;

        return money-(mini1+mini2);

    }
};