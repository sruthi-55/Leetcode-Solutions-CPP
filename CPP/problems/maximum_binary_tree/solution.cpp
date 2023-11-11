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
    int getMaxIndex(vector<int>& nums,int left,int right){
        int maxI = left;
        for(int i=left;i<=right;i++){
            if(nums[maxI]<nums[i])  maxI=i;
        }
        return maxI;
    }
    TreeNode* solve(vector<int> &nums,int left,int right){
        if(left>right)  return NULL;
        
        int maxI = getMaxIndex(nums,left,right);
        TreeNode *root = new TreeNode(nums[maxI]);

        root->left = solve(nums,left,maxI-1);
        root->right = solve(nums,maxI+1,right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};