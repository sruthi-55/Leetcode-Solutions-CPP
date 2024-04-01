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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool isLToR = true;
        while(!q.empty()){
            int sz = q.size();
            vector<int> level(sz,-1);
            for(int i=0;i<sz;i++){
                TreeNode* curNode = q.front();
                q.pop();
                if(isLToR)  level[i]=curNode->val;
                else    level[sz-i-1]=curNode->val;

                if(curNode->left)   q.push(curNode->left);
                if(curNode->right)  q.push(curNode->right);
            }
            isLToR = !isLToR;
            ans.push_back(level);
        }
        return ans;
    }
};
