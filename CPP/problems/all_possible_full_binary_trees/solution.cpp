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
    unordered_map<int, vector<TreeNode*>> dp;
    //full binary tree - has exactly 0 or 2 children
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        //left and right subtrees can have 1,3,5,7,9....
        //if left have i nodes, then right will have n-i-1 ('cause 1 for root)
        if(dp[n].size()!=0) return dp[n];
        if(n%2==0)  return ans;
        if(n==1)    ans.push_back(new TreeNode(0));
        
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-i-1);
            for(auto leftE:left){
                for(auto rightE:right){
                    TreeNode *root = new TreeNode(0);
                    root->left=leftE;
                    root->right=rightE;
                    ans.push_back(root);
                }
            }
        }
        return dp[n]=ans;
    }
};