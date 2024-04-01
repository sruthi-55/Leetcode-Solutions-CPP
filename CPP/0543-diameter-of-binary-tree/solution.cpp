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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD=0;
        getHeight(root,maxD);
        return maxD;
    }
    int getHeight(TreeNode* root,int &maxD){
        if(!root)   return 0;

        int lh = getHeight(root->left,maxD);
        int rh = getHeight(root->right,maxD);
        maxD = max(maxD,lh+rh);
        return 1+max(lh,rh);
    }
};
