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
    void getSum(TreeNode* root,int &sum,bool isLeft){
        if(!root)   return ;

        if(!root->left && !root->right){
            if(isLeft){
                sum+=root->val;
            }
            return ;
        }

        getSum(root->left,sum,true);
        getSum(root->right,sum,false);
        return ;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        getSum(root,sum,false);
        return sum;
    }
};

                            


                  
