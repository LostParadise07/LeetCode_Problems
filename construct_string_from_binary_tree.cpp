/*
Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.

 

*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void pot(TreeNode* root,string & s){
        if(root==NULL){
            return ;
        }
        s+=to_string(root->val);
        if(root->left or root->right){
            s+="(";
            pot(root->left,s);
            s+=")";
        }
        if(root->right){
            s+="(";
            pot(root->right,s);
            s+=")";
        }
    }
    string tree2str(TreeNode* root) {
        if(root==nullptr)
            return "";
        string s="";
        pot(root,s);
        return s;
    }
};