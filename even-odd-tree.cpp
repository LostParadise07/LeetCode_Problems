/*
A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, 
their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly 
increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly 
decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.
*/
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root)
            return true;
        
        queue<TreeNode*> levelQueue;
        levelQueue.push(root);
        int level = 0;
        
        while (!levelQueue.empty()) {
            int currLevelSize = levelQueue.size();
            int prevNodeVal = (level % 2 == 0) ? 0 : 1000001;
            
            while (currLevelSize-- > 0) {
                TreeNode* currNode = levelQueue.front();
                levelQueue.pop();
                int currNodeVal = currNode->val;
                
                // Checks for naming even-odd binary tree
                if (level % 2 == 0) {
                    if (prevNodeVal >= currNodeVal || currNodeVal % 2 == 0)
                        return false;
                } else {
                    if (prevNodeVal <= currNodeVal || currNodeVal % 2 == 1)
                        return false;
                }
                
                prevNodeVal = currNodeVal;
                if (currNode->left)
                    levelQueue.push(currNode->left);
                if (currNode->right)
                    levelQueue.push(currNode->right);
            }
            level++;
        }
        return true;
    }
};