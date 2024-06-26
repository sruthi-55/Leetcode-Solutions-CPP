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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root); 
    }
    bool isMirror(TreeNode* lRoot,TreeNode* rRoot){
        if(!lRoot && !rRoot)    return true;
        if(!lRoot || !rRoot)    return false;

        if(lRoot->val!=rRoot->val)  return false;
        return isMirror(lRoot->left,rRoot->right) &&
                isMirror(lRoot->right,rRoot->left);
    }
};
