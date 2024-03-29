/*
You are given the root of a binary tree with unique values, and an integer start. 
At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.
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
class Solution{
public:
    int amountOfTime(TreeNode* root, int start) {
        int time = 0;    
        
        unordered_map<TreeNode*,TreeNode*> parent;
        FindParent(root,parent);
        
        TreeNode* target = Find(root,start);
        
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;       

        q.push(target);
        vis[target] = true;

        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                auto front = q.front();
                q.pop();
                vis[front] = true;

                if(front->left and !vis[front->left])
                {
                    q.push(front->left);
                    vis[front->left] = true;
                }

                if(front->right and !vis[front->right])
                {
                    q.push(front->right);
                    vis[front->right] = true;
                }

                if(parent[front] and !vis[parent[front]])
                {
                    q.push(parent[front]);
                    vis[parent[front]] = true;
                }
            }
            time++;
        }
        return time-1;
    }    
private:
    TreeNode* Find(TreeNode* node, int key) 
    {
        if(node== NULL) return NULL;

        if(node->val == key) return node;        
        else {
            TreeNode* foundNode = Find(node->left,key);
            if(!foundNode) foundNode = Find(node->right,key);              
            return foundNode;
        }
    }
    void FindParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent)
    {
        if(!root)return;
        if(root->left) parent[root->left] = root;     
        if(root->right) parent[root->right] = root;
        FindParent(root->left,parent);
        FindParent(root->right,parent);
    }
};