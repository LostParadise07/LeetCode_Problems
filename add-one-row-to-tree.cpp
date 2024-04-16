/*
Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
*/

class Solution {

    public TreeNode helper(TreeNode root,int val,int depth,int currdepth){
        if(depth==1){
            TreeNode zoo=new TreeNode(val);
            zoo.left=root;
            return zoo;
        }

        if(root==null){
            return root;
        }

        if(currdepth==depth-1){
            TreeNode leftman=root.left;
            TreeNode rightman=root.right;

            root.left=new TreeNode(val);
            root.right=new TreeNode(val);

            root.left.left=leftman;
            root.right.right=rightman;
            return root;
            
        }

        helper(root.left,val,depth,currdepth+1);
        helper(root.right,val,depth,currdepth+1);

        return root;

    }
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
     return  helper(root,val,depth,1);

        
    }
}