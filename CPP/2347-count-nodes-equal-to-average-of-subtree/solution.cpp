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
    int sum(TreeNode* root){
        if(!root)   return 0;
        return root->val+sum(root->left)+sum(root->right);
    }
    int count(TreeNode* root){
        if(!root)   return 0;
        return 1+count(root->left)+count(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root)   return 0;
        return (sum(root)/count(root)==root->val)+
            averageOfSubtree(root->left)+averageOfSubtree(root->right);
    }
};
