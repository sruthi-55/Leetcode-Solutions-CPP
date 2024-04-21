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
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        int lCount = countNodes(root->left);
        int rCount = countNodes(root->right);
        return 1 + lCount + rCount;
    }
    bool dfs(TreeNode* cur, int curInd, int totalNodes){
        if(!cur)    return true;
        if(curInd>totalNodes)   return false;

        bool left = dfs(cur->left,curInd*2,totalNodes);
        bool right = dfs(cur->right,curInd*2+1,totalNodes);

        return left && right;
    }
    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);
        return dfs(root,1,totalNodes);
    }
};


