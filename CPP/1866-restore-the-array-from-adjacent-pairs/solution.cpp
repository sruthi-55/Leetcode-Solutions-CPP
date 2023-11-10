class Solution {
public:
    vector<int> result;
    void solve(int node, int par, unordered_map<int, vector<int>> &adj) {
        result.push_back(node);
        for(auto nei : adj[node]) {
            if(nei != par) {
                solve(nei, node, adj);
            }
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for(auto p:adjacentPairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        
        int startPoint = -1;
        for(auto it : adj) {
            if(it.second.size() == 1) {
                startPoint = it.first;
                break;
            }
        }
        
        solve(startPoint, INT_MIN, adj);
        return result;
    }
};
