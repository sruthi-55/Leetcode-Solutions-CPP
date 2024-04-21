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
    TreeNode* solve(TreeNode* root, set<int> &st,vector<TreeNode*> &res){
        if(!root)    return NULL;

        root->left = solve(root->left,st,res);
        root->right = solve(root->right,st,res);

        if(st.count(root->val)){
            if(root->left)  res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            return NULL;
        }
        else    return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st;
        for(auto e:to_delete)   
            st.insert(e);
        
        vector<TreeNode*> res;
        TreeNode* rootNode = solve(root,st,res);
        if(rootNode)    res.push_back(rootNode); 
        return res;
    }
};
