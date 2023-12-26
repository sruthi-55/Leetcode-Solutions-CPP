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
    vector<TreeNode*> solve(int s,int e){
        if(s>e)    return {NULL};

        vector<TreeNode*> ans;
        for(int root=s;root<=e;root++){
            vector<TreeNode*> left = solve(s,root-1);
            vector<TreeNode*> right = solve(root+1,e);

            for(int l=0;l<left.size();l++){
                for(int r=0;r<right.size();r++){
                    TreeNode* rootNode = new TreeNode(root,left[l],right[r]);
                    ans.push_back(rootNode);
                }
            }
            
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};
