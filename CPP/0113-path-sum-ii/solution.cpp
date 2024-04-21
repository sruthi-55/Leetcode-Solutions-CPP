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
    void dfs(TreeNode* root, int pathSum, vector<int> &path,int targetSum,vector<vector<int>> &res){
        if(!root)   return ;

        path.push_back(root->val);
        pathSum+=root->val;

        if(!root->left && !root->right && pathSum==targetSum)
            res.push_back(path);

        dfs(root->left,pathSum,path,targetSum,res);
        dfs(root->right,pathSum,path,targetSum,res);

        path.pop_back();
        pathSum -= root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        int pathSum = 0;
        dfs(root,pathSum,path,targetSum,res);
        return res;
    }
};
