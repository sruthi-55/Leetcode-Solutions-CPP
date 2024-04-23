/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <sstream>
class Codec {
public:
    string serialize(TreeNode* root) {
        string s="";
        if(!root)   return s;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node){
                s+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
            else{
                s+="#,";
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if(data.empty())    return nullptr;

        stringstream s(data);
        string str;
        queue<TreeNode*> q;

        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s,str,',');
            if(str!="#"){
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
            }

            getline(s,str,',');
            if(str!="#"){
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
            }

            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
