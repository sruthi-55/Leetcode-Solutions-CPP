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
    int res=0;
    pair<int,int> postorder(TreeNode* root){
        if(!root)   return {};

        pair<int,int> leftP = postorder(root->left);
        pair<int,int> rightP = postorder(root->right);
        int sum = leftP.first + rightP.first + root->val;
        int count = leftP.second + rightP.second + 1;
        if(root->val == sum/count)  res++;
        
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        postorder(root);
        return res;
    }
};