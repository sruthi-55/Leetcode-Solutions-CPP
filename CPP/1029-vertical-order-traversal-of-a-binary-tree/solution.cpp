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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        map<int,map<int,multiset<int>>> mp;
        //{v,{l,node}}
        queue<pair<int,pair<int,TreeNode*>>> q;
        q.push({0,{0,root}});
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto cur = q.front();
                q.pop();

                int v = cur.first;
                int l = cur.second.first;
                TreeNode* node = cur.second.second;
                mp[v][l].insert(node->val);

                if(node->left){
                    q.push({v-1,{l+1,node->left}});
                }
                if(node->right){
                    q.push({v+1,{l+1,node->right}});
                }
            }
        }

        for(auto vEntry:mp){
            vector<int> vertical;
            for(auto lEntry:vEntry.second){
                vertical.insert(vertical.end(),lEntry.second.begin(),lEntry.second.end());
            }
            ans.push_back(vertical);
        }
        return ans;
    }
};
