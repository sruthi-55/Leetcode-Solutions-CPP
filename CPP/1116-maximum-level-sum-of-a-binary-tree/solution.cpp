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
    int maxLevelSum(TreeNode* root) {
        if(!root)   return 0;

        int maxSum = INT_MIN,maxLevel=0;
        queue<TreeNode*> q;
        q.push(root);
        int curLevel = 0;
        while(!q.empty()){
            int sz = q.size();
            curLevel++;
            int curLevelSum = 0;
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();

                curLevelSum += node->val;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(curLevelSum > maxSum){
                maxLevel = curLevel;
                maxSum = curLevelSum;
            }
        }
        return maxLevel;
    }
};
