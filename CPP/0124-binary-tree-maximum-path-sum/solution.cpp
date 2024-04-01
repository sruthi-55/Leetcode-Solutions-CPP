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
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        findMaxSum(root,maxSum);
        return maxSum;
    }
    int findMaxSum(TreeNode* root,int &maxSum){
        if(!root)   return 0;

        int lSum = max(0,findMaxSum(root->left,maxSum));
        int rSum = max(0,findMaxSum(root->right,maxSum));
        maxSum = max(maxSum,root->val+lSum+rSum);

        return root->val+max(lSum,rSum);
    }
};
