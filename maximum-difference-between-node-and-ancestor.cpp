/*
Given the root of a binary tree, find the maximum value v for which there exist 
different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child 
of a is an ancestor of b.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans=0;
    void solve(TreeNode* root,int mini,int maxi){
        if(!root)
        return ;
        maxi = max(maxi,root->val);
        mini = min(mini,root->val);
        ans = max(ans,maxi-mini);
        solve(root->left,mini,maxi);
        solve(root->right,mini,maxi);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        int mini , maxi ;
        mini = maxi = root->val;
        solve(root,mini,maxi);
        return ans;
    }
};