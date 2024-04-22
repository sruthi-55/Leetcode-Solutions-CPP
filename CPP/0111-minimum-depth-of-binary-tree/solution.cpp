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
    int solve(TreeNode* root){
        if(!root)   return 0;
        if(!root->left && !root->right) return 1;

        int left = root->left ? solve(root->left) : INT_MAX;
        int right = root->right ? solve(root->right) : INT_MAX;
        
        return 1 + min(left,right);
    }
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        return solve(root);
    }
};
