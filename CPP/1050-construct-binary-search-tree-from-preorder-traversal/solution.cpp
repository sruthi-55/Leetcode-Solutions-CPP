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
    int i=0;
    TreeNode* bstFromPreorder(vector<int>& preorder,int parVal=INT_MAX) {
        if(i==preorder.size() || preorder[i]>parVal)    return NULL;
        int curVal = preorder[i];
        i++;
        TreeNode* root=new TreeNode(curVal);
        root->left = bstFromPreorder(preorder,curVal);
        root->right = bstFromPreorder(preorder,parVal);
        return root;
    }
};
