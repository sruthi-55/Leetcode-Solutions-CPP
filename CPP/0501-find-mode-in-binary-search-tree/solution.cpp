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
    
    void inorder(TreeNode* root,vector<int> &mode,int &curMode,int &curFreq,int &maxFreq){
        if(!root)   return;
        inorder(root->left,mode,curMode,curFreq,maxFreq);

        if(root->val == curMode){
            curFreq++;
        }
        else{
            curFreq=1;
            curMode = root->val;
        }

        if(curFreq > maxFreq){
            mode.clear();
            maxFreq = curFreq;
        }  
        if(curFreq == maxFreq)  
            mode.push_back(root->val);

        inorder(root->right,mode,curMode,curFreq,maxFreq);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> mode;
        if(!root)   return mode;
        
        int curMode=0,curFreq=0,maxFreq=0;
        inorder(root,mode,curMode,curFreq,maxFreq);
        return mode;
    }
};
