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
    bool dfs(TreeNode* root, int pathSum, int targetSum){
        if(!root)   return false;

        pathSum += root->val;
        if(!root->left && !root->right && pathSum==targetSum)  return true;

        bool left = dfs(root->left,pathSum,targetSum);
        bool right = dfs(root->right,pathSum,targetSum);

        pathSum -= root->val;
        if(left || right)   return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,0,targetSum);
    }
};
