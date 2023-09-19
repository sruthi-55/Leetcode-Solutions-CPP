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
    int sumL=0,maxDepth=0;
    int deepestLeavesSum(TreeNode* root,int depth=0) {
        if(!root)   return 0;
        if(!root->left && !root->right){
            if(depth>maxDepth){
                maxDepth=depth;
                sumL=root->val;
            }  
            else if(depth==maxDepth)    sumL+=root->val;
        }
        deepestLeavesSum(root->left,depth+1);
        deepestLeavesSum(root->right,depth+1);
        return sumL;
    }
};
