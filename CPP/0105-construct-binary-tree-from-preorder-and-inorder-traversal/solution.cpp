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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int pS,int pE,int iS,int iE,unordered_map<int,int> &mp){
        if(pS>pE || iS>iE)  return NULL;

        int rootVal = preorder[pS];
        int rootInd = mp[rootVal];
        //elements in left subtree
        int numsLeft = rootInd - iS;

        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder,inorder, pS+1,pE+numsLeft,iS,rootInd-1,mp);
        root->right = solve(preorder,inorder, pS+numsLeft+1,pE,rootInd+1,iE,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)    mp[inorder[i]]=i;

        return solve(preorder,inorder,0,n-1,0,n-1,mp);
    }
};
