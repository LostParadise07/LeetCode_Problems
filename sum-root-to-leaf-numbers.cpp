/*
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.
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
class Solution {
public:
    void solve(TreeNode* root,int total,int &sum){
        total=10*total+root->val;
        
        if(root->left==NULL && root->right==NULL){
            sum=sum+total;
            return;
        }
        if(root->left)
        solve(root->left,total,sum);
        if(root->right)
        solve(root->right,total,sum);

    }
    
    int sumNumbers(TreeNode* root) {
        
        int sum=0;
        solve(root,0,sum);
        return sum;

    }
};
