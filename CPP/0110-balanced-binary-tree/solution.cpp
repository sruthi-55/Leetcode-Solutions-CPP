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
    //Brute Force
    bool isBalanced(TreeNode* root) {
        return checkBalanced(root);
    }
    bool checkBalanced(TreeNode* root){
        if(!root)   return true;

        int lH = getHeight(root->left);
        int rH = getHeight(root->right);

        if(abs(lH-rH)<=1 && 
        checkBalanced(root->left) && checkBalanced(root->right))  
            return true;

        return false;
    }
    int getHeight(TreeNode* root){
        if(!root)   return 0;
        int lH = getHeight(root->left);
        int rH = getHeight(root->right);
        return 1+max(lH,rH);
    }
};
