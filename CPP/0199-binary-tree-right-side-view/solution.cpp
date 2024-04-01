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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        getRightView(root,0,res);
        return res;
    }
    void getRightView(TreeNode* root,int level,vector<int> &res){
        if(!root)   return;
        if(level>=res.size())    res.push_back(root->val);
        else    res[level] = root->val;

        getRightView(root->left,level+1,res);
        getRightView(root->right,level+1,res);
    }
};
