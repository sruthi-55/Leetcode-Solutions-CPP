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
    string solve(TreeNode* root,vector<TreeNode*> &res,unordered_map<string,int> &mp){
        if(!root)   return "";

        string leftStr = solve(root->left,res,mp);
        string rightStr = solve(root->right,res,mp);

        string s = to_string(root->val) + "," + leftStr + "," + rightStr;
        if(mp[s]==1){
            res.push_back(root);
        }
        mp[s]++;
        return s;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string,int> mp;
        string s = solve(root,res,mp);
        return res;
    }
};
