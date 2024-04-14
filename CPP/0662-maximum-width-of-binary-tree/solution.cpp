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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        long long maxWidth = INT_MIN;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int sz = q.size();

            long long first,last;
            long long minInd = q.front().second;
            
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front().first;
                long long ind = q.front().second - minInd;
                q.pop();

                if(i==0)    first=ind;
                if(i==sz-1) last=ind;

                if(node->left)  q.push({node->left,ind*2+1});
                if(node->right) q.push({node->right,ind*2+2});
            }
            maxWidth = max(maxWidth,last-first+1);
        }
        return maxWidth;
    }
};
