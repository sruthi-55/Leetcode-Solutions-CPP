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
    string preorder(TreeNode* root){
        string str;
        if(!root)   return "";

        str+=to_string(root->val);
        string left = preorder(root->left);
        string right = preorder(root->right);
        
        if((left!="" && right!="") || (left=="" && right!="")){
            str+=("("+left+")");
            str+=("("+right+")");
        }
        else if(left!="" && right==""){
            str+=("("+left+")");
        } 
        else    return str;
        return str;
    }
    string tree2str(TreeNode* root) {
        return preorder(root);
    }
};
