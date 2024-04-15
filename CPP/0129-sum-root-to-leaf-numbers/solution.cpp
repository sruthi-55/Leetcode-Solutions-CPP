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
    void getSum(TreeNode* root,int curSum,int &totalSum){
        if(!root)   return ;

        curSum = curSum * 10 + root->val;
        if(!root->left && !root->right){
            totalSum += curSum;
            return ;
        }
        getSum(root->left,curSum,totalSum);
        getSum(root->right,curSum,totalSum);

    }
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        int curSum = 0;
        getSum(root,curSum,totalSum);
        return totalSum;
    }
};
