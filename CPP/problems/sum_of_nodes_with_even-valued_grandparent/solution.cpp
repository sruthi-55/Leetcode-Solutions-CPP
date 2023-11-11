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
    int sumT=0;
    int sumEvenGrandparent(TreeNode* root,int par=-1,int gPar=-1) {
        if(!root)   return 0;
        if(gPar%2==0)   sumT+=root->val;
        sumEvenGrandparent(root->left,root->val,par);
        sumEvenGrandparent(root->right,root->val,par);
        return sumT;
    }
};