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
    int maxPathLen = 0;
    void solve(TreeNode* root,bool cameFromLeft,int steps){
        if(!root)   return ;

        maxPathLen = max(maxPathLen, steps);

        if(cameFromLeft){
            solve(root->right,false,steps+1);
            solve(root->left,true,1);
        }
        else{
            solve(root->left,true,steps+1);
            solve(root->right,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(!root)   return 0;

        solve(root,false,0);
        solve(root,true,0);
        return maxPathLen;
    }
};
