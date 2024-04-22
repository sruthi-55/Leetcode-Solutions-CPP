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
    int mod = 1e9+7;
    int getTotalSum(TreeNode* root){
        if(!root)   return 0;

        int lSum = getTotalSum(root->left);
        int rSum = getTotalSum(root->right);
        return root->val+lSum+rSum;
    }
    int computeMaxProductFromSum(TreeNode* root,long totalSum,long &maxProduct){
        if(!root)   return 0;
        int lSum = computeMaxProductFromSum(root->left,totalSum,maxProduct);
        int rSum = computeMaxProductFromSum(root->right,totalSum,maxProduct);

        int sum = root->val+lSum+rSum;
        maxProduct = max(maxProduct, sum*(totalSum-sum));
        return sum;
    }
    int maxProduct(TreeNode* root) {
        long totalSum = getTotalSum(root);
        long maxProduct=0;
        computeMaxProductFromSum(root,totalSum,maxProduct);
        return maxProduct%mod;
    }
};
