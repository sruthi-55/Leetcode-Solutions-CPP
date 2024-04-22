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
    int formNumAndGetSum(TreeNode* root,int curSum){
        if(!root)   return 0;

        curSum = curSum * 10 + root->val;
        if(!root->left && !root->right){
            return curSum;
        }

        int lSum = formNumAndGetSum(root->left,curSum);
        int rSum = formNumAndGetSum(root->right,curSum);

        return lSum+rSum;
    }

    int sumNumbers(TreeNode* root) {
        int curSum = 0;
        return formNumAndGetSum(root,curSum);
    }
};
